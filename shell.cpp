#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>

#include "shell.hpp"

Shell::Shell() : input(std::cin), output(std::cout)
{ }

Shell::Shell(std::istream &in, std::ostream &out) : input(in), output(out)
{ }

bool Shell::command::is_background()
{
	return *argv[argc - 1].rbegin() == '&';
}

int Shell::start()
{
	while(1)
	{
		// Display the user prompt
		output << prompt();

		// Read the use input into the command string
		std::string input_command;
		std::getline(input, input_command);

		// Ignore empty inputs
		if (input_command.empty()) continue;

		// Execute the command
		execute(input_command);
	}

	return 0;
}

std::string Shell::prompt()
{
	// Get the hostname of the machine
	char hostname[1024];
	gethostname(hostname, sizeof hostname);

	std::ostringstream prompt;

	prompt << hostname << "(" << getenv("USER") << ")$ ";

	return prompt.str();
}

Shell::command Shell::parse_command(std::string input_command)
{
	// Tokenize the input command into a vector
	std::istringstream iss(input_command);
	std::vector<std::string> argv;

	copy(std::istream_iterator<std::string>(iss),
	     std::istream_iterator<std::string>(),
	     std::back_inserter<std::vector<std::string> >(argv));

	command command;

	// Setup the command struct
	command.command = input_command;
	command.argv    = argv;
	command.argc    = command.argv.size();
	command.name    = command.argv[0];

	return command;
}

int Shell::execute(std::string input_command)
{
	return execute(parse_command(input_command));
}

int Shell::execute(Shell::command)
{

}

/**
 * Begin execution
 */
int main(int argc, char* argv[])
{
	Shell shell;

	return shell.start();
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>

#include "shell.hpp"
#include "commands.hpp"

Shell::Shell()
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
		std::cout << prompt();

		// Read the use input into the command string
		std::string input_command;
		std::getline(std::cin, input_command);

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
	// Tokenize the input command into a vector of strings
	std::istringstream iss(input_command);
	std::vector<std::string> argv;

	copy(std::istream_iterator<std::string>(iss),
	     std::istream_iterator<std::string>(),
	     std::back_inserter<std::vector<std::string> >(argv));

	// We also want the arguments as a vector of C style strings
	std::vector<const char *> argv_c;

	for (int i = 0; i < argv.size(); ++i)
	{
		argv_c.push_back(argv[i].c_str());
	}

	// Setup the command struct
	command command;

	command.command = input_command;
	command.name    = argv[0];
	command.argc    = argv.size();
	command.argv    = argv;
	command.argv_c  = argv_c;

	return command;
}

int Shell::execute(std::string input_command)
{
	return execute(parse_command(input_command));
}

int Shell::execute(Shell::command command)
{
	// Check if the command is a built in function of the shell
	int(*internal_call)() = commands::internal_commands()[command.name];

	if (internal_call != 0)
	{
		return internal_call();
	}








}

/**
 * Begin execution
 */
int main(int argc, char* argv[])
{
	Shell shell;

	return shell.start();
}

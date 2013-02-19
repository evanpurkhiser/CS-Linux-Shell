#include <sstream>
#include <algorithm>
#include <iterator>

#include "parse_command.hpp"

command parse_command(std::string input_command)
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

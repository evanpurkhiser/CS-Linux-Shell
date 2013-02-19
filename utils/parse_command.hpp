#ifndef UTIL_PARSE_COMMAND_HPP
#define UTIL_PARSE_COMMAND_HPP

#include <string>
#include <vector>

struct command
{
	std::string              command;
	std::string              name;
	int                      argc;
	std::vector<std::string> argv;
};

/**
 * Parse a command string into a command struct
 *
 * @param  string The command to parse
 * @return        The command struct
 */
command parse_command(std::string);

#endif

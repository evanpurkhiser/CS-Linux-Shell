#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "utils/parse_command.hpp"

int main(int argc, char* argv[])
{
	while (1)
	{
		// Get the hostname of the machine
		char hostname[1024];
		gethostname(hostname, sizeof hostname);

		// Display the command prompt
		printf("%s (%s)%% ", hostname, getenv("USER"));

		// Read the use input into the command string
		std::string input_command;
		std::getline(std::cin, input_command);

		// Ignore empty commands
		if (input_command.empty()) continue;

		// Parse the command into the command struct
		command command = parse_command(input_command);
	}

	return 0;
}

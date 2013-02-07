#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "utils/parse_command.h"
#include "commands/commands.h"


int main(int argc, char *argv[], char *envp[])
{
	char input_command[MAX_COMMAND_LENGTH];
	struct command_t* command;

	while (1)
	{
		// Get the hostname of the machine
		char hostname[1024];
		gethostname(hostname, sizeof hostname);

		// Display the command prompt
		printf("%s (%s)%% ", hostname, getenv("USER"));

		// Wait for user input
		fgets(input_command, sizeof input_command, stdin);

		// Parse the command input into the command_t struct
		parse_command(command, input_command);





	}



	return 0;
}

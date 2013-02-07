#include <stdlib.h>
#include <string.h>
#include "parse_command.h"

void parse_command(struct command_t* command, char* command_string)
{
	int argc = 0;
	char** argv;
	char** cmd_ptr = &command_string;

	do
	{
		command->argv[argc] = (char*) malloc(MAX_ARGUMENT_LENGTH);
	}
	while (0);

	// Free up that last bit of memory we malloced, it won't have been used
	free(command->argv[--argc]);

	command->argc    = argc;
	command->name    = command->argv[0];
	command->command = command_string;
}

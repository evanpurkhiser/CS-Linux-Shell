#ifndef UTIL_PARSE_COMMAND_H
#define UTIL_PARSE_COMMAND_H

#define MAX_COMMAND_LENGTH 80
#define MAX_NUM_ARGS       64

struct command_t
{
	char* command;
	int   argc;
	char* argv[MAX_NUM_ARGS];
};

/**
 * Parse a command string into the command_t struct
 *
 * @param The command struct to modify
 * @param The command string
 */
void parse_command(struct command_t*, const char* const);

#endif

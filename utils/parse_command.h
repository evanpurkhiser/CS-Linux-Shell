#ifndef UTIL_PARSE_COMMAND_H
#define UTIL_PARSE_COMMAND_H

#define MAX_COMMAND_LENGTH  80
#define MAX_ARGUMENT_LENGTH 16
#define MAX_ARGUMENT_COUNT  64
#define WHITESPACE_CHARS    " \t\n"

struct command_t
{
	char  command[MAX_COMMAND_LENGTH];
	char* name;
	int   argc;
	char* argv[MAX_ARGUMENT_COUNT];
};

/**
 * Parse a command string into the command_t struct.
 *
 * The user is responsable to free the memory used by the argv char** once it is
 * no longer needed
 *
 * @param The command struct to modify
 * @param The command string
 */
void parse_command(struct command_t*, char*);

#endif

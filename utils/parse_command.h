#define MAX_COMMAND_LENGTH 80
#define MAX_NUM_ARGS       64

struct command_t
{
	const char* command;
	const int   argc;
	const char* argv[MAX_NUM_ARGS];
};

struct command_t* parse_command(const char* const command);

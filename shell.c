#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 80


int main(int argc, char *argv[], char *envp[])
{
	char input_command[MAX_COMMAND_LENGTH];

	while (1)
	{
		// Get the hostname of the machine
		char hostname[1024];
		gethostname(hostname, sizeof hostname);

		// Display the command prompt
		printf("%s (%s)%% ", hostname, getenv("USER"));

		// Wait for user input
		fgets(input_command, MAX_COMMAND_LENGTH, stdin);
	}



	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[])
{
	char hostname[1024];
	gethostname(hostname, sizeof hostname);

	printf("%s (%s)%% ", hostname, getenv("USER"));

	return 0;
}

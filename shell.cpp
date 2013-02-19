#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>




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
		std::string command;
		std::getline(std::cin, command);

		// Ignore empty commands
		if (command.empty()) continue;





		std::cout << "whoo!";
	}



	return 0;
}

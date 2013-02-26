#include <map>
#include <iostream>

#include "commands.hpp"

namespace commands
{
	std::map<std::string, int(*)()> internal =
	{
		{"quit",    &quit},
		{"exit",    &quit},
		{"logout",  &quit},
		{"help",    &help},
		{"echo",    &echo},
		{"clr",     &clr},
		{"killall", &killall},
		{"pause",   &pause},
		{"dir",     &dir},
		{"cd",      &cd},
		{"jobs",    &jobs},
		{"environ", &environ},
	};

	int quit()
	{

	}

	int help()
	{

	}

	int echo()
	{

	}

	int clr()
	{
		std::cout << "\033[2J\033[1;1H";
	}

	int killall()
	{

	}

	int pause()
	{
		std::cout << "Console paused. Press <ENTER> to resume.";

		while (std::cin.get() != '\n');
	}

	int dir()
	{

	}

	int cd()
	{

	}

	int jobs()
	{

	}

	int environ()
	{

	}
}

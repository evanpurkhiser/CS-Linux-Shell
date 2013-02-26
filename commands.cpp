#include <map>
#include <iostream>

#include "commands.hpp"

namespace commands
{
	std::map<std::string, int(*)(Shell *, Shell::command *)> internal =
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

	int quit(Shell *shell, Shell::command *cmd)
	{

	}

	int help(Shell *shell, Shell::command *cmd)
	{

	}

	int echo(Shell *shell, Shell::command *cmd)
	{

	}

	int clr(Shell *shell, Shell::command *cmd)
	{
		std::cout << "\033[2J\033[1;1H";
	}

	int killall(Shell *shell, Shell::command *cmd)
	{

	}

	int pause(Shell *shell, Shell::command *cmd)
	{
		std::cout << "Console paused. Press <ENTER> to resume.";

		while (std::cin.get() != '\n');
	}

	int dir(Shell *shell, Shell::command *cmd)
	{

	}

	int cd(Shell *shell, Shell::command *cmd)
	{

	}

	int jobs(Shell *shell, Shell::command *cmd)
	{

	}

	int environ(Shell *shell, Shell::command *cmd)
	{

	}
}

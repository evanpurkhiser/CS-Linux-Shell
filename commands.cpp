#include <map>
#include <iostream>

#include "commands.hpp"

namespace commands
{
	std::map<std::string, int(*)(Shelly *, Shelly::command *)> internal =
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

	int quit(Shelly *shell, Shelly::command *cmd)
	{
		shell->finish();
	}

	int help(Shelly *shell, Shelly::command *cmd)
	{

	}

	int echo(Shelly *shell, Shelly::command *cmd)
	{

	}

	int clr(Shelly *shell, Shelly::command *cmd)
	{
		std::cout << "\033[2J\033[1;1H";
	}

	int killall(Shelly *shell, Shelly::command *cmd)
	{

	}

	int pause(Shelly *shell, Shelly::command *cmd)
	{
		std::cout << "Console paused. Press <ENTER> to resume.";

		while (std::cin.get() != '\n');
	}

	int dir(Shelly *shell, Shelly::command *cmd)
	{
		system(("/bin/ls -l " + cmd->argv[1]).c_str());
	}

	int cd(Shelly *shell, Shelly::command *cmd)
	{
		if (chdir(cmd->argv.size() < 2 ? getenv("HOME") : cmd->argv_c[1]) < 0)
		{
			std::cout << "Unable to change directory\n";
		}
	}

	int jobs(Shelly *shell, Shelly::command *cmd)
	{

	}

	int environ(Shelly *shell, Shelly::command *cmd)
	{

	}
}

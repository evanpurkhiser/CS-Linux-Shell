#include <map>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "commands.hpp"

namespace commands
{
	std::map<std::string, int(*)(Shelly &, const Shelly::command &)> internal =
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

	int quit(Shelly &shell, const Shelly::command &)
	{
		shell.finish();

		return 0;
	}

	int help(Shelly &, const Shelly::command &)
	{
		// Get the path to the manual page
		char bin_path[1024];
		int size = readlink("/proc/self/exe", bin_path, sizeof(bin_path) - 1);
		std::string path(bin_path, size);
		path = path.substr(0, path.find_last_of('/')) + "/../shelly.1";

		return system(("/usr/bin/man " + path).c_str());
	}

	int echo(Shelly &, const Shelly::command &cmd)
	{
		for (int i = 1; i < cmd.argc; ++i)
		{
			std::cout << cmd.argv[i] << " ";
		}

		if (cmd.argc > 1)
		{
			std::cout << '\n';
		}

		return 0;
	}

	int clr(Shelly &, const Shelly::command &)
	{
		std::cout << "\033[2J\033[1;1H";

		return 0;
	}

	int killall(Shelly &shell, const Shelly::command &)
	{
		shell.termiate_jobs();

		return 0;
	}

	int pause(Shelly &, const Shelly::command &)
	{
		std::cout << "Console paused. Press <ENTER> to resume.";

		while (std::cin.get() != '\n');

		return 0;
	}

	int dir(Shelly &, const Shelly::command &cmd)
	{
		std::string path = cmd.argc > 1 ? cmd.argv[1] : ".";

		return system(("/bin/ls -l " + path).c_str());
	}

	int cd(Shelly &, const Shelly::command &cmd)
	{
		if (chdir(cmd.argc < 2 ? getenv("HOME") : cmd.argv_c[1]) < 0)
		{
			std::cout << cmd.name << ": unable to change directory\n";

			return 1;
		}

		return 0;
	}

	int jobs(Shelly &shell, const Shelly::command &)
	{
		for (auto job : shell.jobs_list())
		{
			std::cout << "[" << job.pid << "] " << job.cmd.command << '\n';
		}

		return 0;
	}

	int environ(Shelly &, const Shelly::command &)
	{
		const std::string shell_token = "SHELL=";

		// Get the path to the shell binary
		char shell_bin[1024];
		int end = readlink("/proc/self/exe", shell_bin, sizeof(shell_bin) - 1);
		shell_bin[end] = '\0';

		// Get the environment variables for this process
		std::ifstream environment("/proc/self/environ");
		std::string variable;

		while ( ! std::getline(environment, variable, '\0').eof())
		{
			if (variable.substr(0, shell_token.size()) == shell_token)
			{
				variable = shell_token + shell_bin;
			}

			std::cout << variable << '\n';
		}

		return 0;
	}
}

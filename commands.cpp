#include <map>
#include <iostream>

#include "commands.hpp"

namespace commands
{
	namespace internal
	{
		std::map<std::string, int(*)()> map;

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

	std::map<std::string, int(*)()> internal_commands()
	{
		if (internal::map.empty())
		{
			internal::map["quit"]    = &internal::quit;
			internal::map["exit"]    = &internal::quit;
			internal::map["logout"]  = &internal::quit;
			internal::map["help"]    = &internal::help;
			internal::map["echo"]    = &internal::echo;
			internal::map["clr"]     = &internal::clr;
			internal::map["killall"] = &internal::killall;
			internal::map["pause"]   = &internal::pause;
			internal::map["dir"]     = &internal::dir;
			internal::map["cd"]      = &internal::cd;
			internal::map["jobs"]    = &internal::jobs;
			internal::map["environ"] = &internal::environ;
		}

		return internal::map;
	}
}



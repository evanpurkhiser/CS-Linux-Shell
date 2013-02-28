#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <map>
#include <string>

#include "shelly.hpp"

namespace commands
{
	/**
	 * Get a list of the internal commands
	 */
	extern std::map<std::string, int(*)(Shelly &, const Shelly::command &)>
	internal;

	/**
	 * Terminate the shell after killing all children processes.
	 *
	 * @return Exit status
	 */
	int quit(Shelly &, const Shelly::command &);

	/**
	 * Display the manual / help page for the shell
	 *
	 * @return Exit status
	 */
	int help(Shelly &, const Shelly::command &);

	/**
	 * Display the message passed to echo (with a trailing newline)
	 *
	 * @return Exit status
	 */
	int echo(Shelly &, const Shelly::command &);

	/**
	 * Clear the screen
	 *
	 * @return Exit status
	 */
	int clr(Shelly &, const Shelly::command &);

	/**
	 * Terminate all background prcesses
	 *
	 * @return Exit status
	 */
	int killall(Shelly &, const Shelly::command &);

	/**
	 * Pauses execution of the shell until the user presses the `<ENTER>`
	 * key
	 *
	 * @return Exit status
	 */
	int pause(Shelly &, const Shelly::command &);

	/**
	 * Proxy for `ls -l directory`
	 *
	 * @return Exit status
	 */
	int dir(Shelly &, const Shelly::command &);

	/**
	 * Change the directory
	 *
	 * @return Exit status
	 */
	int cd(Shelly &, const Shelly::command &);

	/**
	 * Lists all currently executing background processes
	 *
	 * @return Exit status
	 */
	int jobs(Shelly &, const Shelly::command &);

	/**
	 * Lists all current environment variables
	 *
	 * @return Exit status
	 */
	int environ(Shelly &, const Shelly::command &);
}

#endif

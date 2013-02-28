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
	extern std::map<std::string, int(*)(Shelly &, Shelly::command &)> internal;

	/**
	 * Terminate the shell after killing all children processes.
	 *
	 * @return Exit status
	 */
	int quit(Shelly &, Shelly::command &);

	/**
	 * Display the manual / help page for the shell
	 *
	 * @return Exit status
	 */
	int help(Shelly &, Shelly::command &);

	/**
	 * Display the message passed to echo (with a trailing newline)
	 *
	 * @return Exit status
	 */
	int echo(Shelly &, Shelly::command &);

	/**
	 * Clear the screen
	 *
	 * @return Exit status
	 */
	int clr(Shelly &, Shelly::command &);

	/**
	 * Terminate all background prcesses
	 *
	 * @return Exit status
	 */
	int killall(Shelly &, Shelly::command &);

	/**
	 * Pauses execution of the shell until the user presses the `<ENTER>`
	 * key
	 *
	 * @return Exit status
	 */
	int pause(Shelly &, Shelly::command &);

	/**
	 * Proxy for `ls -l directory`
	 *
	 * @return Exit status
	 */
	int dir(Shelly &, Shelly::command &);

	/**
	 * Change the directory
	 *
	 * @return Exit status
	 */
	int cd(Shelly &, Shelly::command &);

	/**
	 * Lists all currently executing background processes
	 *
	 * @return Exit status
	 */
	int jobs(Shelly &, Shelly::command &);

	/**
	 * Lists all current environment variables
	 *
	 * @return Exit status
	 */
	int environ(Shelly &, Shelly::command &);
}

#endif

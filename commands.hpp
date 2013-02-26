#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <map>
#include <string>

#include "shell.hpp"

namespace commands
{
	/**
	 * Get a list of the internal commands
	 */
	extern std::map<std::string, int(*)(Shell *, Shell::command  *)> internal;

	/**
	 * Terminate the shell after killing all children processes.
	 *
	 * @return Exit status
	 */
	int quit(Shell *, Shell::command *);

	/**
	 * Display the manual / help page for the shell
	 *
	 * @return Exit status
	 */
	int help(Shell *, Shell::command *);

	/**
	 * Display the message passed to echo (with a trailing newline)
	 *
	 * @return Exit status
	 */
	int echo(Shell *, Shell::command *);

	/**
	 * Clear the screen
	 *
	 * @return Exit status
	 */
	int clr(Shell *, Shell::command *);

	/**
	 * Terminate all background prcesses
	 *
	 * @return Exit status
	 */
	int killall(Shell *, Shell::command *);

	/**
	 * Pauses execution of the shell until the user presses the `<ENTER>`
	 * key
	 *
	 * @return Exit status
	 */
	int pause(Shell *, Shell::command *);

	/**
	 * Proxy for `ls -l directory`
	 *
	 * @return Exit status
	 */
	int dir(Shell *, Shell::command *);

	/**
	 * Change the directory
	 *
	 * @return Exit status
	 */
	int cd(Shell *, Shell::command *);

	/**
	 * Lists all currently executing background processes
	 *
	 * @return Exit status
	 */
	int jobs(Shell *, Shell::command *);

	/**
	 * Lists all current environment variables
	 *
	 * @return Exit status
	 */
	int environ(Shell *, Shell::command *);
}

#endif

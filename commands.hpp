#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <map>
#include <string>

namespace commands
{
	/**
	 * Get a list of the internal commands
	 */
	std::map<std::string, int(*)()> internal_commands();

	namespace internal
	{
		/**
		 * Terminate the shell after killing all children processes.
		 *
		 * @return Exit status
		 */
		int exit();

		/**
		 * Display the manual / help page for the shell
		 *
		 * @return Exit status
		 */
		int help();

		/**
		 * Display the message passed to echo (with a trailing newline)
		 *
		 * @return Exit status
		 */
		int echo();

		/**
		 * Clear the screen
		 *
		 * @return Exit status
		 */
		int clr();

		/**
		 * Terminate all background prcesses
		 *
		 * @return Exit status
		 */
		int killall();

		/**
		 * Pauses execution of the shell until the user presses the `<ENTER>`
		 * key
		 *
		 * @return Exit status
		 */
		int pause();

		/**
		 * Proxy for `ls -l directory`
		 *
		 * @return Exit status
		 */
		int dir();

		/**
		 * Change the directory
		 *
		 * @return Exit status
		 */
		int cd();

		/**
		 * Lists all currently executing background processes
		 *
		 * @return Exit status
		 */
		int jobs();

		/**
		 * Lists all current environment variables
		 *
		 * @return Exit status
		 */
		int environ();
	}
}

#endif

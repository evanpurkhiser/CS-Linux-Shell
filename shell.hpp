#ifndef SHELL_HPP
#define SHELL_HPP

#include <string>
#include <iostream>
#include <vector>

class Shell
{
	public:

		/**
		 * Defines a command
		 */
		struct command
		{
			std::string               command;
			std::string               name;
			int                       argc;
			std::vector<std::string>  argv;
			std::vector<const char *> argv_c;
			bool                      background;
		};

		/**
		 * Construct the shell object
		 */
		Shell();

		/**
		 * Continously display a input prompt for a user to execute commands
		 *
		 * @return The exit status of the shell object
		 */
		virtual int start();

		/**
		 * Generate the command prompt text
		 *
		 * @return The command prompt text
		 */
		virtual std::string prompt();

		/**
		 * Parse a input string into a command struct
		 *
		 * @param  The command to parse
		 * @return The command
		 */
		virtual command parse_command(std::string);

		/**
		 * Executes a command by passing a string
		 *
		 * @param  The command string to execute
		 * @return The exit status of the command
		 */
		int execute(std::string);

		/**
		 * Executes a command by passing a command struct
		 *
		 * @param  The command to execute
		 * @return The exit status of the command
		 */
		int execute(command);
};

#endif

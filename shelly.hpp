#ifndef SHELLY_HPP
#define SHELLY_HPP

#include <string>
#include <vector>
#include <list>

class Shelly
{
	public:

		/**
		 * Hard limit on the number of background jobs that may be run
		 */
		static const int MAX_BG_JOBS = 3;

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
		 * Defines a background job
		 */
		struct job
		{
			command cmd;
			int     pid;
		};

		/**
		 * Construct the shell object
		 */
		Shelly();

		/**
		 * Continously display a input prompt for a user to execute commands
		 *
		 * @return The exit status of the shell object
		 */
		virtual int start();

		/**
		 * Let the shell finish
		 */
		virtual void finish();

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
		virtual int execute(std::string);

		/**
		 * Executes a command by passing a command struct
		 *
		 * @param  The command to execute
		 * @return The exit status of the command
		 */
		virtual int execute(command);

		/**
		 * Terminate all background jobs
		 */
		virtual void termiate_jobs();

		/**
		 * Return a list of background jobs. When only completed background
		 * jobs are asked for, then these jobs will be removed from the
		 * background jobs list and returned as a std::list of jobs
		 *
		 * @param  If true then only return a list of completed background jobs
		 * @return A list of jobs
		 */
		virtual std::list<job> jobs_list(bool = false);

	protected:

		/**
		 * A list of currently running jobs
		 */
		std::list<job> background_jobs;

		/**
		 * A flag to exit the shell
		 */
		bool exit;
};

#endif

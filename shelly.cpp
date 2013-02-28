#include <cstdlib>
#include <csignal>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <sys/wait.h>
#include <unistd.h>

#include "shelly.hpp"
#include "commands.hpp"

Shelly::Shelly() : exit(false)
{ }

int Shelly::start()
{
	while( ! exit)
	{
		// Display the user prompt
		std::cout << prompt();

		// Read the use input into the command string
		std::string input_command;
		std::getline(std::cin, input_command);

		// Exit on EOF
		if (std::cin.eof())
		{
			std::cout << (input_command = "exit") << '\n';
		}

		// List out any jobs that have completed
		for (auto job : jobs_list(true))
		{
			std::cout << "[" << job.pid << "] Done : " << job.cmd.command
			          << '\n';
		}

		// Ignore empty inputs
		if (input_command.empty()) continue;

		// Execute the command
		execute(input_command);
	}

	return 0;
}

void Shelly::finish()
{
	termiate_jobs();
	exit = true;
}

std::string Shelly::prompt()
{
	char  hostname[1024];
	char *username = getenv("USER");
	gethostname(hostname, sizeof hostname);

	return std::string("\033[0;35m") + hostname + "(" + username + ")%\033[0m ";
}

Shelly::command Shelly::parse_command(std::string input_command)
{
	// Setup the command struct
	command command;

	// This command is a background job if the last character is a '&'
	command.background = input_command.back() == '&';

	// Remove the background flag from the command string
	if (command.background)
	{
		input_command.erase(input_command.size() - 1);
	}

	// Tokenize the input command into a vector of strings
	std::istringstream iss(input_command);
	std::vector<std::string> argv;

	copy(std::istream_iterator<std::string>(iss),
	     std::istream_iterator<std::string>(),
	     std::back_inserter<std::vector<std::string> >(argv));

	// We also want the arguments as a vector of C style strings
	std::vector<const char *> argv_c;

	for (auto arg : argv)
	{
		argv_c.push_back(arg.c_str());
	}

	command.command = input_command;
	command.name    = argv[0];
	command.argc    = argv.size();
	command.argv    = argv;
	command.argv_c  = argv_c;

	return command;
}

int Shelly::execute(std::string input_command)
{
	return execute(parse_command(input_command));
}

int Shelly::execute(Shelly::command command)
{
	int status = 0;

	// Check if the command is a built in function of the shell
	int(*internal_command)(Shelly &, const Shelly::command &);

	if ((internal_command = commands::internal[command.name]) != 0)
	{
		return internal_command(*this, command);
	}

	int pid = fork();

	if (pid == 0)
	{
		// execvp always expects the last argument to be a null terminator
		command.argv_c.push_back(0);

		// Because the argv_c vector stores the C-strings in order we can
		// simply de-refrence the first element of the argv_c vector
		execvp(command.argv_c[0], (char * const *) &command.argv_c[0]);

		// exec failed, the command was _probably_ not found
		std::cerr << command.name << ": command not found\n";
		finish();
	}
	else
	{
		if (command.background)
		{
			if (background_jobs.size() < Shelly::MAX_BG_JOBS)
			{
				background_jobs.push_back({command, pid});
				std::cout << "[" << pid << "] " << command.command << '\n';

				return status;
			}

			// Let the user know only so many commands may be run in the bg
			std::cerr << "No more than " << Shelly::MAX_BG_JOBS
			          << " background jobs may be run at once.\n"
			          << "Executing " << command.name << " in the foreground\n";
		}

		wait(&status);
	}

	return status;
}

void Shelly::termiate_jobs()
{
	for (auto job : background_jobs)
	{
		kill(job.pid, SIGTERM);
		wait(0);
	}

	background_jobs.clear();
}

std::list<Shelly::job> Shelly::jobs_list(bool completed)
{
	if ( ! completed)
	{
		return background_jobs;
	}

	std::list<Shelly::job> completed_jobs;
	std::list<Shelly::job>::iterator it;

	// Get completed jobs and splice them into the completed_jobs list
	for (it = background_jobs.begin(); it != background_jobs.end(); ++it)
	{
		// Check if the process is not done yet
		if (waitpid(it->pid, 0, WNOHANG) == 0) continue;

		completed_jobs.splice(completed_jobs.end(), background_jobs, it--);
	}

	return completed_jobs;
}

/**
 * Begin execution
 */
int main(int, char**)
{
	Shelly Shelly;
	return Shelly.start();
}

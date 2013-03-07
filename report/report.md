# 3460:426 Operating Systems - Project 1

Authored by Evan Purkhiser.

## Overview

_Shelly_ is a extremely rudimentary UNIX command line interpreter. This program
uses the [`execvp`](http://linux.die.net/man/3/execvp) function from the UNIX
standard library to execute binary files located in the environment `PATH`. The
shell supports some extra features such as running commands in the background
and handling internal commands line `cd`, `environ`, `killall`, etc..

## Source code and File list

The fully project history for _Shelly_ can be found on my GitHub located at:  
https://github.com/EvanPurkhiser/OS-Shell

The following source files are required to build the project

    |- commands.hpp
    |- commands.cpp
    |- shelly.hpp
    |- shelly.cpp
    |- shelly.1
    \- Makefile

Some additional files are also included with the project relating to additional
details, including:

    |- LICENSE.md
    \- README.md

## Building Shelly from source

Simply run the following command: `make`. The Shelly binary will be written to
the `bin` directory in the source folder.

## Designing and Implementing Shelly

Initially when beginning this project I was quite headstrong about writing
Shelly purely in the C language. Only after about 2 hours of work fiddling with
`malloc` and `free` did I remember why writing in C was basically like an
writing in a macro version of Assembly. It didn't take much longer before I
threw what I had done out the window and went ahead and changed `gcc` to `g++`
in my Makefile.

Deciding on C++ opened up a world of design options. I wanted to spend some time
designing my classes with SRP in mind and ensuring low cohesion. In the end I
decided on just having one class named `Shelly`. This class would be responsible
for reading a command from `STDIN`, parsing the command, and then deciding how
to execute it. I would also have a group of free functions in a namespace, these
free functions would map to the internal commands.

### Using the Shelly object

Shelly consists of two primary methods `start()` and `finish()`.

  * `Shelly::start()` handles _starting_ the endless loop that would handle
    displaying the prompt, reading input from `STDIN`, and finally executing the
    command.

  * `Shelly::finish()` terminates will kill any and all background process and
    then set a flag on the object instruction the endless loop to end, thus
    allowing the `start()` method to return cleanly

### Parsing the input command

Command parsing is handled by the `Shelly::parse_command()` method. This method
accepts a string and will return a `Shelly::command` struct. The command struct
includes various pieces of information about the command to be executed.

    struct command
    {
    	std::string               command;
    	std::string               name;
    	int                       argc;
    	std::vector<std::string>  argv;
    	std::vector<const char *> argv_c;
    	bool                      background;
    };

Most of this sturcture is self explanatory, however a few parts may need some
clarification.

 * I store two version of `argv`, one is a vector of `std::string`s, the other
   is a vector of C style strings. I do this so we can easily handle argv items
   for certain commands using the C++ style `std::strings`, while at the same
   time being able to pass

 * The `background` member of the struct indicates if the command should be
   executed in the background or not.

This structure will be returned after parsing a command string.

### Executing a command

The Shelly class contains a method for handling execution of commands,
`Shelly::execute()`. There are two implementations of this method, one accepts
a command struct, while the other accepts a plain command string.

    int Shelly::execute(std::string input_command)
    {
    	return execute(parse_command(input_command));
    }

As you can see, the real meat of the command execution happens in the execute
method that accepts a command struct.

The execute method process a command in the following order

 1. Check if the command name is defined as an internal command. If so execute
    the internal command and return the execution status.

 2. If the command is not internal then fork the process and execute the command
    using `execvp` if possible.

 3. If the command's `background` property is `false` then wait for the child
    process to finish before returning from execution.

 4. Likewise, if the `background` property is `true` then ensure that no more
   than two background jobs are currently executing. If these tests pass then
   immediately return from execution while the child process executes in the
   background.

If execvp is to fail we must ensure that the child process finishes execution.
If we neglect to handle this case then many child shells will continue to run
in the background of our main shell. We can easily handle this situation by
placing our failure code after the execvp.

    execvp(command.argv_c[0], (char * const *) &command.argv_c[0]);

    // exec failed, the command was _probably_ not found
    std::cerr << command.name << ": command not found\n";
    finish();

### Executing internal commands

Shelly's internal commands all exist as free functions in the namespace
`commands`. Within this namespace we also initialize a map of strings to
function pointers. This allows us an easy interface for determining if a command
can be executed via an internal function or not.

    std::map<std::string, internal_function> internal =
    {
    	{"quit",    &quit},
    	{"exit",    &quit},
    	{"help",    &help},
    	...
    	{"cd",      &cd},
    	{"jobs",    &jobs},
    	{"environ", &environ},
    };

Each of these commands share a common interface as defined by the
`internal_function` typedef. Each function should accept the Shell object it's
being called from, as well as the executing command struct.

    typedef int(*internal_function)(Shelly &, const Shelly::command &);

Each internal command should do the work required, and then return an exit code.

### Job handling

Any time a command is executed in the background a `job` is added to a list of
background processes currently in execution. A job simply consists of the PID of
the process in execution as well as the command struct which initiated the
process.

    struct job
    {
        command cmd;
        int     pid;
    };

Each time that an `EOL` is passed through `STDIN` the jobs list is pruned of
jobs that have finished executing. This is done by using the `waitpid` function
to determine if each of the background processes has completed execution or not.
The pruned jobs will then be printed to `STDOUT` notifying the user of which
background processes have completed.

## Final thoughts

This project was actually rather fun to work on. While I had been exposed to
most of the concepts used in this program during UNIX programming, it was a good
chance to refresh my memory of C++, as well as a nice opportunity to play with
the latest C++11 features.

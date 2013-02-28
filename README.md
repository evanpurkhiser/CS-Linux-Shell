# Shelly - A Linux shell for 3460:426 Operating Systems

This is Shelly, a extreamly simple shell program designed to run on GNU/Linux
based operating systems. The shell provides very basic functionality with no
configuration. This includers some built in caommands as well as the ability
to disown commands and have them run in the background.

See the [assignment PDF](http://www.cs.uakron.edu/~toneil/cs426/lab1.pdf) for
more detailed information on this project.

### Building Shelly

There are two branches of Shelly available. `master` and `g++4.4`. The master
branch requires the latest C++11 features to be available. This means you need
at least g++ version 4.6 or later to compile Shelly without errors.

Compiling Shelly is a piece of cake, you will want to make sure you have the
correct branch checked out for your version of g++ (you can check which g++
you have by running `g++ --version`). And all you need to do is execute the
Makefile.

    $ git checkout master
    $ make

That's it! You can now run the Shelly binary

    $ ./bin/shelly

### License

This software is licensed under the MIT License. See the
[LICENSE file](./LICENSE.md).

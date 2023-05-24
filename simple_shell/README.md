# Simple Shell

Simple Shell is a basic UNIX command line interpreter implemented in C. It provides a simple interface for users to execute commands, handle built-in functionalities, and perform variable substitution. The shell supports various features such as executing external commands, handling built-in commands, environment variables, aliases, and file input.

## Features

- Execute external commands
- Handle built-in commands: exit, env, cd, alias
- Perform variable substitution using environment variables ($VAR) and special variables ($?, $$)
- Support command execution from a file
- Handle comments (#) in command input
- Support command separation with ;, logical operators && and ||
- Change the current working directory and update the PWD environment variable
- Print and manage aliases

## Getting Started

To compile the shell, run the following command: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh



To run the shell in interactive mode, use: ./simple_shell


To run the shell in batch mode with a file, use: ./simple_shell [filename]



## Usage

Once the shell is running, you can type commands and execute them. Here are some examples:

$ ls
$ pwd
$ cd /path/to/directory
$ alias list="ls -l"
$ list
$ exit



For more information on the supported commands and usage, refer to the documentation.

## Documentation

The documentation for the Simple Shell project can be found in the [docs](./docs) directory. It includes detailed explanations of the shell's features, supported commands, and usage examples.

## Contributing

Contributions to the Simple Shell project are welcome! If you find any bugs, have suggestions, or want to add new features, please open an issue or submit a pull request.

## License

This project has no official license, however completed part of ALX SE internship in collaboration with Holberton school.

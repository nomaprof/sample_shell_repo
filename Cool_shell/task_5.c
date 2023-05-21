#include "cool_shell.h"

/* Declare the external variable */
char **commands = NULL;
char *input = NULL;
char *name_of_shell = NULL;
int status = 0;

/**
 * main - my shell program
 * @argc: number of arguments
 * @argv: the arguments
 *
 * Return: beautiful shell program
 */

int main(int argc, char **argv)
{
	char **command_now = NULL;
	int m;
	int command_parsed = 0;
	size_t input_length = 0;
	(void)argc;

	signal(SIGINT, exit_handler);
	name_of_shell = argv[0];

	while (1)
	{
		not_interacting();
		display("Shell > ", STDOUT_FILENO);
		
		/* Read user input */
		if (getline(&input, &input_length, stdin) == -1)
		{
			free(input);
			exit(status);
		}
		no_newline(input);
		erase_comment(input);

		/* Tokenize the input to get the command and arguments */
		commands = tokenizer(input, ";");
		
		for (m = 0; commands[m] != NULL; m++)
		{
			command_now = tokenizer(commands[m], " ");
			if (command_now[0] == NULL)
			{
				free(command_now);
				break;
			}
			/* Handle the Path */
			command_parsed = determine_command(command_now[0]);
			/* Execute the command */
			executor(command_now, command_parsed);
			free(command_now);
		}
		free(commands);
	}
	free(input);
	return (status);
}

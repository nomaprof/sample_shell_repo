#include "cool_shell.h"

/**
 * exit_handler - takes care of signal sent by ctrl+c
 * @signalid: number used to identify the signal
 *
 * Return: no value
 */
void exit_handler(int signalid)
{
	if (signalid == SIGINT)
	{
		display("\n($) ", STDIN_FILENO);
	}
}

/**
 * erase_comment - ignores anything after a "#" character)
 * @filein: the file
 *
 * Return: no value
 */
void erase_comment(char *filein)
{
	int m = 0;

	if (filein[m] == '#')
	{
		filein[m] = '\0';
	}
	while (filein[m] != '\0')
	{
		if (filein[m] == '#' && filein[m - 1] == ' ')
		{
			break;
		}
		m++;
	}
	filein[m] = '\0';
}

/**
 * not_interacting - non-interactive command handling
 * Return: no value
 */

void not_interacting(void)
{
	char **command_now = NULL;
	int m;
	int command_parsed = 0;
	size_t input_length = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&input, &input_length, stdin) != -1)
		{
			no_newline(input);
			erase_comment(input);
			commands = tokenizer(input, ";");

			for (m = 0; commands[m] != NULL; m++)
			{
				command_now = tokenizer(commands[m], " ");
				if (command_now[0] == NULL)
				{
					free(command_now);
					break;
				}
				command_parsed = determine_command(command_now[0]);
				executor(command_now, command_parsed);
				free(command_now);
			}
			free(commands);
		}
		free(input);
		exit(status);
	}
}

/**
 * no_newline - removes newline
 * @string: the string
 *
 * Return: void
 */

void no_newline(char *string)
{
	int m = 0;

	while (string[m] != '\0')
	{
		if (string[m] == '\n')
		{
			break;
		}
		m++;
	}
	string[m] = '\0';
}

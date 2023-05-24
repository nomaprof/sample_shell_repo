#include "cool_shell.h"

/**
 * whichfunc - get the function that executes the command
 * @command: the user instruction
 *
 * Return: no value
 */

void(*whichfunc(char *command))(char **)
{
	int m;

	function_map mapping[] = {
		{"env", env}, {"exit", stop},
	};

	for (m = 0; m < 2; m++)
	{
		if (cmpstr(command, mapping[m].command_identity) == 0)
		{
			return (mapping[m].func);
		}
	}
	return (NULL);
}

/**
 * determine_command - is the command external, path, or internal
 * @command: the command index
 *
 * Return: the command type
 * Description - OUTSIDE_COMMAND(1)
 * INSIDE_COMMAND(2)
 * ROUTE_COMMAND(3)
 * INCORRECT_COMMAND(-1)
*/

int determine_command(char *command)
{
	int m;
	char *inside_command[] = {"env", "exit", NULL};
	char *route = NULL;

	for (m = 0; command[m] != '\0'; m++)
	{
		if (command[m] == '/')
		{
			return (OUTSIDE_COMMAND);
		}
	}
	for (m = 0; inside_command[m] != NULL; m++)
	{
		if (cmpstr(command, inside_command[m]) == 0)
		{
			return (INSIDE_COMMAND);
		}
	}
	route = path_check(command);
	if (route != NULL)
	{
		free(route);
		return (ROUTE_COMMAND);
	}
	return (INCORRECT_COMMAND);
}

/**
 * env - get the environment variable
 * @elemental_command: command passed
 *
 * Return: no value
 */
void env(char **elemental_command __attribute__((unused)))
{
	int m;

	for (m = 0; environ[m] != NULL; m++)
	{
		display(environ[m], STDOUT_FILENO);
		display("\n", STDOUT_FILENO);
	}
}

/**
 * stop - leaves the shell
 * @elemental_command: user command
 *
 * Return: no value
 */
void stop(char **elemental_command)
{
	int token_number = 0;
	int argm;

	for (; elemental_command[token_number] != NULL; token_number++)
	{
		;
	}

	if (token_number == 1)
	{
		free(elemental_command);
		free(input);
		free(commands);
		exit(status);
	}
	else if (token_number == 2)
	{
		argm = _atoi(elemental_command[1]);
		if (argm == -1)
		{
			display(name_of_shell, STDERR_FILENO);
			display(": 1: exit: Illegal number: ", STDERR_FILENO);
			display(elemental_command[1], STDERR_FILENO);
			display("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(input);
			free(elemental_command);
			free(commands);
			exit(argm);
		}
	}
	else
	{
		display(" $ : exit does not take more than one argument\n", STDERR_FILENO);
	}
}

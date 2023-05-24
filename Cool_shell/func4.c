#include "cool_shell.h"

/**
 * path_check - confirm if a command is in the path
 * @command: the user command
 *
 * Return: the path
 */

char *path_check(char *command)
{
	char **array_for_path = NULL;
	char *hold1, *hold2, *cpy_path;
	char *path = whichenv("PATH");
	int m;

	if (path == NULL || lenstr(path) == 0)
	{
		return (NULL);
	}
	cpy_path = malloc(sizeof(*cpy_path) * (lenstr(path) + 1));
	cpystr(path, cpy_path);
	array_for_path = tokenizer(cpy_path, ":");
	for (m = 0; array_for_path[m] != NULL; m++)
	{
		hold2 = catstr(array_for_path[m], "/");
		hold1 = catstr(hold2, command);
		if (access(hold1, F_OK) == 0)
		{
			free(hold2);
			free(array_for_path);
			free(cpy_path);
			return (hold1);
		}
		free(hold1);
		free(hold2);
	}
	free(cpy_path);
	free(array_for_path);
	return (NULL);
}

/**
 * whichenv - value of environment parameter
 * @value: name of parameter
 *
 * Return: a string
 */

char *whichenv(char *value)
{
	char **ron;
	char *two;
	char *ans_cpy;

	for (ron = environ; *ron != NULL; ron++)
	{
		for (two = *ron, ans_cpy = value; *two == *ans_cpy; two++, ans_cpy++)
		{
			if (*two == '=')
			{
				break;
			}
			if ((*two == '=') && (*ans_cpy == '\0'))
			{
				return (two + 1);
			}
		}
	}
	return (NULL);
}


/**
 * do_the_command - carry out command
 * @elemental_command: command token
 * @command_identity: command type
 *
 * Return: no value
 */
void do_the_command(char **elemental_command, int command_identity)
{
	void (*func)(char **command);

	if (command_identity == OUTSIDE_COMMAND)
	{
		if (execve(elemental_command[0], elemental_command, NULL) == -1)
		{
			perror(whichenv("PWD"));
			exit(2);
		}
	}
	if (command_identity == ROUTE_COMMAND)
	{
		if (execve(elemental_command[0], elemental_command, NULL) == -1)
		{
			perror(whichenv("PWD"));
			exit(2);
		}
	}
	if (command_identity == INSIDE_COMMAND)
	{
		func = whichfunc(elemental_command[0]);
		func(elemental_command);
	}
	if (command_identity == INCORRECT_COMMAND)
	{
		display(name_of_shell, STDERR_FILENO);
		display(": 1:", STDERR_FILENO);
		display(elemental_command[0], STDERR_FILENO);
		display(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

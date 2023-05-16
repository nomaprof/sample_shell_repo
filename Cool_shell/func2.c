#include "cool_shell.h"

/**
 * display - print to stdout
 * @info: information to print
 * @flow: tracking printed characters
 *
 * Return: printed string
 */

void display(char *info, int flow)
{
	int m =0;

	for (; info[m] != '\0'; m++)
	{
		write(flow, &info[m], 1);
	}
}


/**
 * cpystr - copy a source
 * @thecopied: the source
 * @copier: the destination
 *
 * Return: the source copied to the destination
 */

void cpystr(char *thecopied, char *copier)
{
	int m =0;

	for (; thecopied[m] != '\0'; m++)
	{
		copier[m] = thecopied[m];
	}
	copier [m] = '\0';
}

/**
 * lenstr - length of a string
 * @str: the string
 *
 * Return: the integer representing length of string
 */

int lenstr(char *str)
{
	int span = 0;

	if (str == NULL)
	{
		return (span);
	}
	for (; str[span] != '\0'; span++)
	{
		;
	}
	return (span);
}

/**
 * tokenizer - split user_input by delimiter
 * @buffer: the command and arguments
 * @delim: the delimiter that informs spliting
 *
 * Return: array of strings
 */

char **tokenizer(char *buffer)
{
	int width = 0;
	int size = 16;
	char *delim = " \n";
	char **tokens;
	char *token;
	tokens = malloc(size * sizeof(char*));
	if (!tokens)
	{
		perror("tsh:memory allocation error");
		exit(-1);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		tokens[width] = token;
		width++;
		if (width >= size)
		{
			size = (int) (size * 1.5);
			tokens = realloc(tokens, size * sizeof(char *));
			if (!tokens)
			{
				perror("tsh:memory allocation error");
				exit(-1);
			}
		}
		token =  strtok(NULL, delim);
	}
	tokens[width] = NULL;
	return (tokens);
}

/**
 * user_input - get user input
 *
 * Return: command and argument
 */

char *user_input()
{
	char *input = NULL;
	size_t length  = 0;
	errno = 0;
	getline(&input, &length, stdin);
	if (errno)
	{
		perror("error");
	}
	return (input);
}

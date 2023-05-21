#include "cool_shell.h"

/**
 * display - display to stdout
 * @info: information to display
 * @flow: tracking displayed characters
 *
 * Return: displayed string
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
/* Tokenize the input to get the command and arguments */
char **tokenizer(char *buffer, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int count = 0;
	char *pointer = NULL;
	
	token = mystrtok(buffer, delim, &pointer);

	while (token != NULL)
	{
		tokens = _realloc(tokens, sizeof(*tokens) * count, sizeof(*tokens) * (count + 1));
		tokens[count] = token;
		token = mystrtok(NULL, delim, &pointer);
		count++;
	}
	/* Set the last element to null before calling excve */
	tokens = _realloc(tokens, sizeof(*tokens) * count, sizeof(*tokens) * (count + 1));
	tokens[count] = NULL;
	return (tokens);
}


/**
 * user_input - get user input
 *
 * Return: command and argument
 */
char *user_input()
{
	/* read user input */
	ssize_t input_length = read(0, input, BUFFER_SIZE);
	/* get user input */
	input[input_length - 1] = '\0';
	return (input);
}

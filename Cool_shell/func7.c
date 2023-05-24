#include "cool_shell.h"
/**
 * tokenizer - split user input by delimiter
 * @buffer: the command and argumentss
 * @delim: the delimiter that informs splitting
 *
 * Return: array of strings
 */

/* Tokenize the input to get the command and arguments */

char **tokenizer(char *buffer, char *delim)
{
	char **tok = NULL;
	char *token = NULL;
	int count = 0;
	char *pointer = NULL;

	token = mystrtok(buffer, delim, &pointer);
	while (token != NULL)
	{
		tok = _realloc(tok, sizeof(*tok) * count, sizeof(*tok) * (count + 1));
		tok[count] = token;
		token = mystrtok(NULL, delim, &pointer);
		count++;
	}

	/* Set the last element to NULL before calling execve */

	tok = _realloc(tok, sizeof(*tok) * count, sizeof(*tok) * (count + 1));
	tok[count] = NULL;
	return (tok);
}

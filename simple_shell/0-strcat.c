#include "shell.h"

/**
 * _strcat - the fucntion will take two strings arguments, concatenate them.
 * @dest: argument of type char
 * @src: argument of type char
 * Return: dest
 * Take note that we are using pointers to the function and to the arguments.
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (p);
}

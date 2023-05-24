#include "shell.h"

/**
 * _strchr - customised function that work like builtin function strchr
 * @c:argument two, character to locate occurence
 * @s: argument one, pointer
 * Return: a pointer to the first occurrence of the character
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}

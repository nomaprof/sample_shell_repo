#include "shell.h"

/**
 * _memset - this customised function will work like the builtin memset.
 * @s: argument one, pointer
 * @b: argument two,
 * @n: argument three,constant
 * Return: a pointer
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
	s[i] = b;
	i++;
	}
	return (s);
}

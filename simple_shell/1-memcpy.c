#include "shell.h"

/**
 * _memcpy - customised function that work like the builtin memcpy
 * @n:argument three, function copies
 * @src:argument two, bytes from memory area
 * @dest: argument one, memory area
 * Return: a pointer to @dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

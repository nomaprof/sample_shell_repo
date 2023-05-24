#include "shell.h"

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	if (str)
	{
		int i = 0;

		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
	}
}


#include "shell.h"

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int sign = 1, output = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			output = (output * 10) + (*s - '0');
		}
		else if (output != 0)
		{
			break;
		}

		s++;
	}
	return (output * sign);
}

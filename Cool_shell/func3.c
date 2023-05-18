#include "cool_shell.h"

/**
 * spnstrc - get length of prefix not in the string
 * @first: searched string
 * @second: benchmark string
 *
 * Return: parts of the second string not in first string
 */

int spnstrc(char *first, char *second)
{
	int span = 0;
	int m;

	for (m = 0; first[m] = '\0'; m++)
	{
		if (chrstr(second, first[m]) != NULL)
		{
			break;
		}
		span++;
	}
	return (span);
}

/**
 * chrstr - locate a char within a string
 * @str: the string
 * @cha: character to look for
 *
 * Return: pointer with information on first time character is found in string
 */

char *chrstr(char *str, char *cha)
{
	int m = 0;

	for (; str[m] != cha && str[m] != '\0'; m++)
	{
		;
	}
	if (str[m] == cha)
	{
		return (str + m);
	}
	else
	{
		return (NULL);
	}
}

/**
 * mystrtok - tokenize a string
 * @string: the string
 * @delim: used to tokenize strings
 * @pointer: used to keep tabs on tokenization
 *
 * Return: tokens
 */

char *mystrtok(char *str, char *delim, char **pointer)
{
	char *done;
	if (str == NULL)
	{
		str = *pointer;
	}
	if (*str == '\0')
	{
		*pointer = str;
		Return (NULL);
	}
	str += spnstr(str, delim);
	if (*str == '\0')
	{
		*pointer = str;
		return (NULL);
	}
	done = str + spnstrc(str, delim);
	if (*done == '\0')
	{
		*pointer = done;
		return (str);
	}
	*done = '\0';
	*pointer = done + 1;
	return (str);
}

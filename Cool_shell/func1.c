#include "cool_shell.h"

/**
 * _realloc - reallocates memmory for tokenization
 * @pointer: points to old memory address
 * @old_ans: size of pointer
 *
 * return: new memory pointer
 */

void *_realloc(void *pointer, unsigned int old_ans, unsigned int new_ans)
{
	void *hold;
	unsigned int m;

	if (pointer == NULL)
	{
		hold = malloc(new_ans);
		return (hold);
	}
	else if (new_ans == old_ans)
	{
		return (pointer);
	}
	else if (new_ans == 0 && pointer != NULL)
	{
		free (pointer);
		return (NULL);
	}
	else
	{
		hold = malloc(new_ans);
		if (hold != NULL)
		{
			for (m = 0; m < min(old_ans, new_ans); m++)
			{
				*((char*)hold + m) = *((char*)pointer + m);
			}
			free(pointer);
			return (hold);
		}
		else
		{
			return (NULL);
		}
	}
}

/**
 * _atoi - change argv into integer
 * @str: the string
 *
 * Return: the converted string
 */

int _atoi(char *str)
{
	unsigned int m = 0;

	do
	{
		if (*str == '_')
		{
			return (-1);
		}
		else if ((*str < '0' || *str > '9') && *str != '\0')
		{
			return (-1);
		}
		else if (*str >= '0' && *str <= '9')
		{
			m = (m * 10) + (*str - '0');
		}
		else if (m > 0)
		{
			break;
		}
	}
	while (*str++);
	return (m);
}

/**
 * cmpstr - string comparisons
 * @first: first string
 * @second: second string
 *
 * Return: string that is the difference between two strings
 */

int cmpstr(char *first, char *second)
{
	int m = 0;

	while (first[m] != '\0')
	{
		if (first[m] != second[m])
		{
			break;
		}
		m++
	}
	return (first[m] - second[m]);
}

/**
 * catstr - join strings together
 * @destination: the string getting additions
 * @source: the string to be added
 *
 * Return: pointer to new string
 */

char *catstr(char *destination, char *source)
{
	char *cat_string = NULL;
	int lendes = lenstr(destination);
	int lensou = lenstr(source);

	cat_string =  malloc(sizeof(*cat_string) * (lendes + lensou + 1));
	cpystr(destination, cat_string);
	cpystr(source, cat_string + lendes);
	cat_string[lendes + lensou] = '\0';
	return (cat_string);
}

/**
 * spnstr - get length of prefix substring
 * @first: searched string
 * @second: benchmark string
 *
 * Return: the part of second string in the first string
 */

int spnstr(char *first, char *second)
{
	int m = 0;
	int ans = 0;

	while (first[m] != '\0')
	{
		if (chrstr(second, first[m]) == NULL)
		{
			break;
		}
		ans++;
		m++;
	}
	return (ans);
}

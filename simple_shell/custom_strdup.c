#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0, i;
	char *ret;
	const char *ptr = str;

	if (str == NULL)
		return (NULL);

	while (*ptr)
	{
		length++;
		ptr++;
	}

	ret = malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		ret[i] = str[i];
	}
	return (ret);
}



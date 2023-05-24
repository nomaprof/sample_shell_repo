#include "shell.h"

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	ssize_t r = 0;
	size_t k;
	char *p = *ptr;
	char *new_p = NULL, *c;
	size_t s = (p && length) ? *length : 0;

	if (i == len)
	{
		i = len = 0;
		r = read_buf(info, buf, &len);
		if (r == -1 || (r == 0 && len == 0))
			return (-1);
	}

	c = _strchr(buf + i, '\n');
	k = c ? (unsigned int)(c - buf) + 1 : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);

	if (!new_p)
	{
		if (p)
			free(p);
		return (-1);
	}
	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);
	s += k - i;
	i = k;
	*ptr = new_p;
	if (length)
		*length = s;
	return (s);
}

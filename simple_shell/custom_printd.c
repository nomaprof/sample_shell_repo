#include "shell.h"

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int count = 0;
	unsigned int _abs_ = (input < 0) ? -input : input;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		__putchar('-');
		count++;
	}

	if (_abs_ == 0)
	{
		__putchar('0');
		count++;
	}
	else
	{
		int i = 1000000000;

		while (i > 0)
		{
			if (_abs_ / i || i == 1)
			{
				__putchar('0' + _abs_ / i);
				count++;
			}
			_abs_ %= i;
			i /= 10;
		}
	}
	return (count);
}

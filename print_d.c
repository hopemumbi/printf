#include "main.h"
#include <stdarg.h>

/**
 * print_d - prints an integer with specifier d
 *
 * @args: A list of arguments
 * @buffer: A pointer to the buffer where int is copied to
 * @len: A pointer to the length of the buffer
 *
 * Return: Always 0
 */
int print_d(va_list args, char *buffer, size_t *len)
{
	int num, temp, rem;
	size_t i, size;
	char str[20];

	num = va_arg(args, int);

	temp = num;
	size = 0;
	while (temp != 0)
	{
		size++;
		temp = temp / 10;
	}

	for (i = 0; i < size; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[size - i - 1] = rem + '0';
	}

	for (i = 0; i < size; i++)
	{
		buffer[(*len)++] = str[i];
	}

	return (0);
}

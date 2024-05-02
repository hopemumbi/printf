#include "main.h"
#include <stdarg.h>

/**
 * print_i - prints an integer with specifier i
 *
 * @args: A list of arguments
 * @buffer: A pointer to the buffer where int is copied to
 * @len: A pointer to the length of the buffer
 *
 * Return: Always 0
 */
int print_i(va_list args, char *buffer, size_t *len)
{
	int num;
	size_t i, size;
	char str[30];

	num = va_arg(args, int);
	size = _itoa(num, str);

	for (i = 0; i < size; i++)
	{
		buffer[(*len)++] = str[i];
	}

	return (0);
}

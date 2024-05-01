#include <stdarg.h>
#include "main.h"
/**
 * print_c - Copies a char to a buffer
 *
 * @args: A list of variable arguments
 * @buffer: A pointer to a buffer where characters will be stored.
 * @len:  A pointer to a variable storing the length of the buffer.
 *
 * Return: Always 0
 */
int print_c(va_list args, char *buffer, size_t *len)
{
	char c;

	c = (char)va_arg(args, int);

	buffer[*len] = c;
	(*len)++;
	return (0);
}

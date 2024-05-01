#include <stdarg.h>
#include "main.h"
/**
 * print_s - Copies a formated string to a buffer.
 *
 * @args: A list of arguments; format specifiers
 * @buffer: A pointer to the buffer to copy the string
 * @len: A pointer to the length of the buffer
 *
 * Return: Always 0;
 */
int print_s(va_list args, char *buffer, size_t *len)
{
	char *str;
	size_t i;

	str = va_arg(args, char *);

	i = 0;
	while (str[i] != '\0')
	{
		buffer[*len] = str[i];
		(*len)++;
		i++;
	}
	return (0);
}

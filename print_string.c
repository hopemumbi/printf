#include <stdarg.h>
#include "main.h"
/**
 * print_string - Prints a string with specifier %s.
 *
 * @args: A list of arguments; format specifiers
 *
 * Return: The number of strings printed;
 */
int print_string(va_list args)
{
	char *str;
	size_t i;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

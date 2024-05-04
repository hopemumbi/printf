#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#define CAPACITY 1024

/**
 * _printf - produces output according to a format.
 *
 * @format: A pointer to a format string
 * ...: A list of arguments passed to format specifiers
 *
 * Return: : the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int total_chars = 0;
	format_s flist[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"%", print_percent},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);


	va_start(args, format);
	total_chars = scanner(format, flist, args);
	va_end(args);

	return (total_chars);
}

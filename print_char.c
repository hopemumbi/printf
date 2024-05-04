#include <stdarg.h>
#include "main.h"
/**
 * print_char - Prints a char with specifier %c
 *
 * @args: A list of variable arguments
 *
 * Return: Always 0
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}

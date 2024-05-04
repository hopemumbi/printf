#include "main.h"
#include <stdarg.h>

/**
 * print_integer - prints an integer with specifier %d
 *
 * @args: A list of arguments
 *
 * Return: The count of numbers printed
 */
int print_integer(va_list args)
{
	int num;
	size_t i, size;
	char str[30];

	num = va_arg(args, int);
	size = _itoa(num, str);

	for (i = 0; i < size; i++)
	{
		_putchar(str[i]);
	}

	return (size);
}

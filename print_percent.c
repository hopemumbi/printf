#include "main.h"

/**
 * print_percent - print the percent symbol
 *
 * @args: A list of arguments
 *
 * Return: The number of characters printed
 */
int print_percent(va_list args)
{
	(void)args; /* Unused argument */
	_putchar('%');
	return (1);
}

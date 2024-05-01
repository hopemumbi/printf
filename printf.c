#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - produces output according to a format.
 *
 * @format: A pointer to a format string
 * ...: A list of arguments passed to format specifiers
 *
 * Return: : the number of characters printed (excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j;
	size_t len = 0;
	char buffer[1024];
	format_specifier f[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d}
	};

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++; /* Skip the '%' */
			if (format[i] == '%')
			{
				buffer[len++] = '%';
			}
			else
			{
				j = 0;
				while (j < 3 && (format[i] != *(f[j].specifier)))
					j++;

				if (j < 3)
					f[j].print(args, buffer, &len);
				else
				{
					buffer[len++] = '%';
					buffer[len++] = format[i];
				}
			}

		}
		else
		{
			/* If format specifier not found, treat '%' as a literal character */
			buffer[len++] = format[i];
		}
		i++;
	}
	buffer[len] = '\0';
	write(1, buffer, len);
	va_end(args);
	return (len);
}

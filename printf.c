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
 * Return: : the number of characters printed (excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j;
	size_t len = 0, k;
	char *buffer, *new_buffer;
	format_specifier f[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i}
	};

	if (format == NULL)
		return (-1);

	buffer = (char *)malloc(CAPACITY * sizeof(char));
	if (buffer == NULL)
		return (-1);

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (len >= CAPACITY - 1)
		{
			new_buffer = (char *)malloc((CAPACITY * 2) * sizeof(char));
			if (new_buffer == NULL)
			{
				free(buffer);
				va_end(args);
				return (-1);
			}
			for (k = 0; k < len; k++)
			{
				new_buffer[k] = buffer[k];
			}
			free(buffer);
			buffer = new_buffer;
		}
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
				while (j < 4 && (format[i] != *(f[j].specifier)))
					j++;

				if (j < 4)
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
	free(buffer);
	va_end(args);
	return (len);
}

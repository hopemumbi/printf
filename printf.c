#include <unistd.h>
#include <stdarg.h>
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
	int i = 0;
	size_t len = 0;
	char *str, buffer[1024];

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++; /* Skip the '%' */
			switch (format[i])
			{
				case 'c':
					buffer[len++] = va_arg(args, int);
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str != '\0')
					{
						buffer[len++] = *str++;
					}
					break;
				default:
					buffer[len++] = '%';
					buffer[len++] = format[i];
					break;

			}

		}
		else
		{
			buffer[len++] = format[i];
		}
		i++;
	}
	buffer[len] = '\0';
	write(1, buffer, len);
	va_end(args);
	return (0);
}

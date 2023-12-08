#include <unistd.h>
int _printf(const char *format, ...)
{
	int i = 0;
	size_t len = 0;

	while (format[i] != '\0')
	{
		i++;
		len++;
	}

		write(1, format, len);
	return (0);
}

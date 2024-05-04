#include <stdarg.h>
#include "main.h"

/**
 * scanner - Scans the main string and all the necessary parameters to
 * print a formatted string.
 *
 * @format: A pointer to a format string
 * @flist: A list of all possible functions
 * @args: A list of arguments passed as format specifiers
 *
 * Return: : The total number of characters printed
 */
int scanner(const char *format, format_s flist[], va_list args)
{
	int total_chars = 0;
	int i, j, found = 0;

	if (format == NULL || flist == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)/*Iterate thru string*/
	{
		if (format[i] == '%') /*Check for format specifier*/
		{ /*Iterate through flist to find appropriate match */
			for (j = 0; flist[j].sym != NULL; j++)
			{ /* Check character after % matches symbols in flist*/
				if (format[i + 1] == *(flist[j].sym))
				{
					total_chars += flist[j].print(args);
					found = 1;
					break; /*Break loop once symol is foung*/
				}
			} /* If no match is found, and char after % is a space*/
			if (!found && format[i + 1] != ' ')
			{ /*If char after % is not the null terminator*/
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]); /*Print %*/
					_putchar(format[i + 1]);/*print char after*/
					total_chars += 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			total_chars++;
		}
	}
	return (total_chars);
}

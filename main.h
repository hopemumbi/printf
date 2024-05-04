#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
/**
 *
 *
 *
 *
 */
typedef struct format
{
	char *sym;
	int (*print)(va_list);
} format_s;

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int _itoa(int n, char *str);
int print_integer(va_list args);
int print_percent(va_list args);
int scanner(const char *format, format_s f_list[], va_list args);
int _printf(const char *format, ...);
#endif

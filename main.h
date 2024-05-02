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
typedef struct format_specifier
{
	char *specifier;
	int (*print)(va_list, char *, size_t *);
} format_specifier;

int print_c(va_list args, char *buffer, size_t *len);
int print_s(va_list args, char *buffer, size_t *len);
int _itoa(int n, char *str);
int print_d(va_list args, char *buffer, size_t *len);
int _printf(const char *format, ...);
#endif

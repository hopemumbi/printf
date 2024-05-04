#include <stdio.h>
#include <limits.h> /* for INT_MIN */
#include "main.h"
/**
 * _itoa - converts an integer to a string
 *
 * @n: The integer to be converted
 * @str: Pointer to a character array where the result is stored
 *
 * Return: The length of the resulting string
 */
int _itoa(int n, char *str)
{
	size_t i = 0, a, z;
	int sign, rem;

	if (n == INT_MIN)
	{
		rem = -(n % 10);
		n = -(n / 10);
		str[i++] = '-';
		i += _itoa(n, str + 1);
		str[i++] = '0' + rem;
		str[i] = '\0';
		return (i);
	}
	if (n == 0) /* Handle case where n is '0'*/
		str[i++] = '0';

	sign = n < 0 ? -1 : 1;
	if (sign == -1) /* Handle negative numbers */
	{
		str[i++] = '-';
		n = -n; /* Make positive*/
	}
	while (n != 0) /* Convert each digit of the number to a string*/
	{
		str[i++] = '0' + (n % 10);
		n /= 10;
	}
	str[i] = '\0'; /* Null-terminate the string */

	a = sign == -1 ? 1 : 0; /* Start index for reversal*/
	z = i - 1; /* End index for reversal */
	while (a < z) /* Reverse the string */
	{
		char swap;

		swap = str[a];
		str[a++] = str[z]; /* Increment the start*/
		str[z--] = swap; /* Decrement the end*/
	}
	return (i); /* Return the length of the resulting string */
}

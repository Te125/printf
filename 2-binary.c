#include "printf.h"
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * convert_to_binary - converts unsigned integer to binary
 * @n: unsigned integer
 *
 * Return: string
 */
char *convert_to_binary(unsigned int n)
{
	char *binary = malloc(sizeof(char) * 33);
	int index = 31;

	if (binary == NULL)
		return (NULL);

	binary[32] = '\0';

	if (n == 0)
	{
		binary[index] = '0';
		return (binary);
	}

	while (n > 0)
	{
		binary[index--] = (n & 1) ? '1' : '0';
		n >>= 1;
	}
	return (binary + index + 1);
}

/**
 * handle_binary - handles conversion specifier
 * @args: argument
 * @buffer: to print
 * @pos: position
 *
 * Return: updated position
 */
int handle_binary(va_list args, char *buffer, int pos)
{
	unsigned int n = va_arg(args, unsigned int);
	char *binary = convert_to_binary(n);

	if (binary == NULL)
		return (-1);

	pos += sprintf(&buffer[pos], "%s", binary);

	free(binary);
	return (pos);
}

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int write_char(char *buffer, char c);
int write_hex(char *buffer, char c);

/**
 * print_S - conversion specifier for non-printable characters
 * @args: string argument
 * @buffer: write the output
 *
 * Return: number of characters written to the buffer
 */
int print_S(char *buffer, char *str)
{
	int count = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			count += write_char(buffer, '\\');
			count += write_hex(buffer, (unsigned char) str[i]);
		}
		else
		{
			count += write_char(buffer, str[i]);
		}
	}

	return (count);
}

/**
 * write_char - main
 * @buffer: buffer
 * @c: character
 *
 * Return: number of characters
 */
int write_char(char *buffer, char c)
{
	buffer[0] = c;
	return (1);
}

/**
 * write_hex - main
 * @buffer: buffer
 * @c: character
 *
 * Return: number of characters
 */
int write_hex(char *buffer, char c)
{
	int count;

	count = sprintf(buffer, "%02X", c);
	return (count);
}

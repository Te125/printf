#include "printf.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_unsigned - integer
 * @args: argument
 *
 * Return: number of characters
 */
int print_unsigned(va_list args)
{
	unsigned int arg = va_arg(args, unsigned int);

	return (printf("%u", arg));
}

/**
 * print_octal - octal argument
 * @args: argument
 *
 * Return: number of characters
 */
int print_octal(va_list args)
{
	unsigned int arg = va_arg(args, unsigned int);

	return (printf("%o", arg));
}

/**
 * count_hex_digits - count hexadecimal
 * @num: number
 *
 * Return: number
 */
int count_hex_digits(unsigned int num)
{
	int count = 0;

	while (num != 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}

/**
 * print_hex - hexadecimal argument
 * @args: argument
 *
 * Return: number of characters
 */
void print_hex(va_list args)
{
	unsigned int hex_num = va_arg(args, unsigned int);
	int hex_digits = count_hex_digits(hex_num);
	char *hex_str = malloc(hex_digits + 1);

	if (!hex_str)
		return;

	sprintf(hex_str, "%x", hex_num);

	puts(hex_str);

	free(hex_str);
}

/**
 * print_hex_upper - uppercase hexadecimal
 * @args: argument
 *
 * Return: number of characters
 */
int print_hex_upper(va_list args)
{
	unsigned int arg = va_arg(args, unsigned int);

	return (printf("%X", arg));
}

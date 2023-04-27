#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _printf - produces output to format
 * @format: string
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, printed = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
			len += handle_conversion_specifier(&format, &args, &printed);
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}

	va_end(args);
	return (len + printed);
}

/**
 * handle_conversion_specifier - main
 * @format: string
 * @args: argument
 * @printed: characters
 *
 * Return:number of characters
 */
int handle_conversion_specifier(const char **format, va_list *args, int *printed)
{
	char *s;
	int len = 0;

	(*format)++;
	switch (**format)
	{
		case 'c':
			len++;
			_putchar(va_arg(*args, int));
			break;
		case 's':
			s = va_arg(*args, char*);
			if (s == NULL)
				s = "(null)";
			len += _strlen(s);
			*printed += _puts(s);
			break;
		case '%':
			len++;
			_putchar('%');
			break;
		default:
			len += 2;
			_putchar('%');
			_putchar(**format);
			break;
	}
	return (len);
}

/**
 * _strlen - length of string
 * @s: string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len;

	if (s == NULL)
		return (0);

	for (len = 0; s[len]; len++)
		;

	return (len);
}

/**
 * _puts - write a string
 * @s: string
 *
 * Return: number of characters
 */
int _puts(char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		_putchar(s[len]);

	return (len);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: on success 1.
 * On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

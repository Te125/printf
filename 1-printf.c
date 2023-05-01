#include "printf.h"
#include <stdio.h>
#include <unistd.h>

int printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _puts(char *str)
{
	int i;

	for (i = 0; str[1]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * _printf - main
 * @format: string
 *
 * Return: number of characters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, printed_chars = 0;
	char buffer[1024];

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += _puts(va_arg(args, char*));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				case 'd':
				case 'i':
					sprintf(buffer, "%d", va_arg(args, int));
					printed_chars += _puts(buffer);
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}
	va_end(args);
	return (printed_chars);
}

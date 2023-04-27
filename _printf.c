#include "main.h"

/**
 * _printf - custom
 * @format: string
 *
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format == '%')
	{
		if (*format == '%')
		{
			printed_chars += handle_conversion_specifier(&format, &args, &printed_chars);
			continue;
		}
		printed_chars += write_char(NULL, *format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}

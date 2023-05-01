#include "main.h"

int handle_conversion_specifier(const char **format, va_list *args, int *chars_printed);
int write_char(char *buffer, char c);

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

	while (*format == '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			
			printed_chars += handle_conversion_specifier(&format, &args, &printed_chars);
		}
		else
		{
			printed_chars += write_char(NULL, *format);
			format++;
		}
	}

	va_end(args);

	return (printed_chars);
}

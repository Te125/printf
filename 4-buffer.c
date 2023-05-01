#include "printf.h"
#include <stdio.h>

int handle_specifier(va_list *args, char specifier, char *buffer, int *count);
void write_buffer(char *buffer, int *count);

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			count += handle_specifier(&args, *(++format), buffer, &count);
		}
		else
		{
			buffer[count++] = *format;
		}

		if (count == 1023)
		{
			write_buffer(buffer, &count);
		}
		format++;
	}

	write_buffer(buffer, &count);

	va_end(args);

	return (count);
}

/**
 * handle_specifier - main
 * @args: argument
 * @specifier: specifier
 * @buffer: buffer
 * @count: count
 *
 * Return: number of characters
 */
int handle_specifier(va_list *args, char specifier, char *buffer, int *count)
{
	unsigned int uint_arg;

	switch (specifier)
	{
		case 'd':
		case 'i':
			uint_arg = va_arg(*args, int);
			return (sprintf(&buffer[*count], "%d", uint_arg));
		case 'u':
			uint_arg = va_arg(*args, unsigned int);
			return (sprintf(&buffer[*count], "%u", uint_arg));
		case 's':
			return(sprintf(&buffer[*count], "%s", va_arg(*args, char *)));
		default:
			return (sprintf(&buffer[*count], "%%%c", specifier));
	}
}
/**
 * write_buffer - main
 * @buffer: buffer
 * @count: count
 *
 * Return: nothing
 */
void write_buffer(char *buffer, int *count)
{
	buffer[*count] = '\0';
	printf("%s", buffer);
	*count = 0;
}

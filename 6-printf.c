#include <stdarg.h>
#include <stdio.h>

/**
 * print_pointer - pointer address
 * @args: string argument
 * @buffer: write the output
 *
 * Return: number of characters
 */
int print_pointer(va_list args, char *buffer)
{
	void *ptr_arg;
	int written;

	ptr_arg = va_arg(args, void *);
	written = sprintf(buffer, "%p", ptr_arg);
	return (written);
}

#ifndef PRINTF_H
#define PRINTF_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * struct conversion_specifier - Struct containing information for a
 * printf conversion specifier
 *
 * @specifier: The conversion specifier character
 * @function_ptr: The function pointer to the conversion function
 */
typedef struct conversion_specifier
{
	char specifier;
	int (*function_ptr)(va_list, char *, int);
} conversion_specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *);
int _puts(char *);
char *convert_to_binary(unsigned int n);
int handle_binary(va_list args, char *buffer, int pos);
int print_integer(int num, char *buffer);
int print_unsigned(va_list args);
int print_octal(va_list args);
int count_hex_digits(unsigned int num);
int print_hexadecimal(va_list args);
int print_hex_upper(va_list args);
int print_S(va_list args, char *buffer);
int write_char(char *buffer, char c);
int write_hex(char *buffer, char c);
void write_buffer(void);
int handle_conversion_specifier(const char **format, va_list *args, int *printed);
int handle_specifier(void);
int print_binary(unsigned int num, char *buffer);
int print_string(const char *str, char *buffer);
int print_argument(const char **format, va_list args);
int get-flags(const char *format, int *i);

#endif /* PRINTF_H */

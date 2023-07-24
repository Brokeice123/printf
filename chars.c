#include "main.h"

/**
 * print_char - prints a character
 * @arg: argument to print
 * Return: number of characters printed
 */

int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @arg: argument to print
 * Return: number of characters printed
 */

int print_string(va_list arg)
{
	char *str, chr;
	int i;

	str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		chr = str[i];
		write(1, &chr, 1);
	}
	return (i);
}

/**
 * print_percent - prints a percent symbol
 * @arg: argument to print
 * Return: number of characters printed
 */

int print_percent(__attribute__((unused))va_list arg)
{
	return (write(1, "%", 1));
}

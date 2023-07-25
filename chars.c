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

/**
 *print_string_custom - Prints a string with a specified format
 *@args: Arguments to print
 *Return: Number of args printed
 */

int print_string_custom(va_list args)
{
	char *c = va_arg(args, char *);
	int i;
	char j;


	for (i = 0; c[i] != '\0'; i++)
	{

		j = c[i];

		if (j < 32 || j >= 127)
		{
			write(1, "\\x", 2);
			write(1, &j, 1);
		}

		else
			write(1, &j, 1);
	}

	return (0);

}

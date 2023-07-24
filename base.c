#include "main.h"


/**
 *print_decimal - Print the variable to decimal notation
 *@args: The variable being passed
 *
 * Return: The output
 */

int print_decimal(va_list args)
{
	char buffer[10];
	int i = 10;
	unsigned int value;

	value = va_arg(args, unsigned int);


	while (value)
	{
		buffer[--i] = '0' + value % 10;
		value /= 10;
	}

	if (i == 10)
		buffer[--i] = '0';

	return (write(1, buffer + i, 10 - i));
}

/**
 *print_octal - Prints the variable passed to octal notation
 *@args: The variable passed
 *
 *Return: The output
 */

int print_octal(va_list args)
{
	unsigned int value;
	char buffer[12];
	int i = 12;

	value = va_arg(args, unsigned int);
	buffer[--i] = '\0';

	while (value)
	{
		buffer[--i] = '0' + value % 8;
		value /= 8;
	}

	if (i == 12)
	{
		buffer[--i] = '0';
	}

	return (write(1, buffer + i, 12 - i));
}

/**
 *print_hex - Prints the variable in hexadecimal notation
 *@args: The variable passed
 *
 *Return: The output
 */

int print_hex(va_list args)
{
	unsigned int value;
	char buffer[9];
	int i = 9;

	value = va_arg(args, unsigned int);

	while (value)
	{
		buffer[--i] = "0123456789abcdef"[value & 0xf];
		value >>= 4;
	}

	if (i == 9)
	{
		buffer[--i] = '0';
	}

	return (write(1, buffer + i, 9 - i));
}

/**
 *print_hex_upper - Prints the variable in hexadecimal uppercase notation
 *@args: The variable passed
 *
 *Return: The output
 */

int print_hex_upper(va_list args)
{
	unsigned int value;
	char buffer[9];
	int i = 9;

	value = va_arg(args, unsigned int);

	while (value)
	{
		buffer[--i] = "0123456789ABCDEF"[value & 0xF];
		value >>= 4;
	}

	if (i == 9)
	{
		buffer[--i] = '0';
	}

	return (write(1, buffer + i, 9 - i));
}

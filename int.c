#include "main.h"


/**
 * _abs - finds the absolute value of an integer
 * @num: the number
 *
 * Return: ABsolute value of num
 */

int _abs(int num)
{
	return (num < 0 ? -num : num);
}

/**
 * num_length - Finds the length of the number passed
 * @num: The number to be used
 *
 * Return: The length of num
 */

int num_length(int num)
{
	int length = 1;

	while (num /= 10)
		length++;

	return (length);
}


/**
 * print_int - Prints an integer
 * @args: the va_list that contains the integer to be printed
 *
 * Return: the number of characters printed
 */

int print_int(va_list args)
{
	int num = va_arg(args, int);
	int is_negative = num < 0 ? 1 : 0;
	int num_len = num_length(num);
	int i, length;

	char *buffer = malloc(is_negative + num_len + 1);

	if (buffer == NULL)
		return (-1);

	i = is_negative + num_len;

	buffer[i] = '\0';

	do {
		i--;
		buffer[i] = _abs(num % 10) + '0';
		num /= 10;
	} while (num != 0);


	if (is_negative)
	{
		buffer[0] = '-';
		write(1, buffer, num_len + 1);
	}
	else
		write(1, buffer, num_len);

	length = is_negative + num_len;
	free(buffer);
	return (length);
}

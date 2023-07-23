#include "main.h"

/**
 * char_fmt - formats a character
 * @c: character to format
 * Return: number of characters printed
 */

int char_fmt(char c)
{
	char buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';

	return (_write(buffer, 1));
}

/**
 * string_fmt - formats a string
 * @s: string to format
 * Return: number of characters printed
 */

int string_fmt(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (_write(s, len));
}

/**
 * percent_fmt - formats the percent symbol
 * Return: number of characters printed
 */

int percent_fmt(void)
{
	char percent = '%';

	return (_write(&percent, 1));
}

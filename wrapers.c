#include "main.h"

/**
 * _write - writes the character(s) c to stdout
 * @str: The character(s) to print
 * @len: The length of the str to print
 *
 * Return: On success 1. On error -1.
 */

int _write(const char *str, int len)
{
	return (write(1, str, len));
}

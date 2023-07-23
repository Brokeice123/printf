#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_strlen - Returns the length of a string
 *@s: The string being used
 *Return: Returns the length of the string
 */

int _strlen(char *s)
{
	unsigned int len = 0;
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
		len += sizeof(char);

	return (len);
}

/**
 *_printf -  produces output according to a format
 *@format: a character string
 *
 *Return: Count
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *s;

	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
				count += _putchar(va_arg(args, int));
				break;
				case 's':
				s = va_arg(args, char *);
				count += write(1, s, _strlen(s));
				break;
				case '%':
				count += write(1, "%", 1);
				break;
				default:
				break;
			}
		} else
		{
		count += write(1, format, 1);
		}
	}
	va_end(args);
	return (count);
}

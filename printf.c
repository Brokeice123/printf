#include "main.h"

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
	char c, *s;

	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
				c = (char) va_arg(args, int);
				count += char_fmt(c);
				break;
				case 's':
				s = va_arg(args, char *);
				count += string_fmt(s);
				break;
				case '%':
				count += percent_fmt();
				break;
				default:
				break;
			}
		}
		else
		{
			_write(format, 1);
		}
	}
	va_end(args);
	return (count);
}

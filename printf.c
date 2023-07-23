#include "main.h"

/**
 *_printf -  produces output according to a format
 *@format: a character string
 *
 *Return: Count
 */

int _printf(const char *format, ...)
{
	int chars_written = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
				if (*format == '\0')
					break;

				if (*format == 'c')
				{
					char c = (char) va_arg(args, int);

					chars_written += char_fmt(c);
				}
				else if (*format == 's')
				{
					char *s = va_arg(args, char *);

					chars_written += string_fmt(s);
				}
				else if (*format == '%')
				{
					chars_written += percent_fmt();
				}
			format++;
		}
		else
		{
			_write(format, 1);
			chars_written++;
			format++;
		}
	}

	va_end(args);
	return (chars_written);
}

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

	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			switch (*++format)
			{
				case 'c':
					count += print_char(args);
					break;

				case 's':
					count += print_string(args);
					break;

				case '%':
					count += print_percent(args);
					break;

			}
		}
		else
		{
		count += write(1, format, 1);
		}
	}
	va_end(args);
	return (count);
}

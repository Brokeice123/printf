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

	while (format && *format)
	{
		if (*format == '%')
		{

			format++;

			if (*format == '\0')
				break;
			else if (*format == '%')
				count += write(1, format, 1);
			else if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == 'd' || *format == 'i')
				count += print_int(args);
			else if (*format == 'b')
				count += print_binary(args);
			else if (*format == 'u')
				count += print_decimal(args);
			else if (*format == 'o')
				count += print_octal(args);
			else if (*format == 'x')
				count += print_hex(args);
			else if (*format == 'X')
				count += print_hex_upper(args);
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

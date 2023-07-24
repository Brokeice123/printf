#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(__attribute__((unused))va_list arg);
int print_int(va_list arg);
int num_length(int num);
int _abs(int num);

#endif

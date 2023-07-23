#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);
int _write(const char *str, int len);
int char_fmt(char c);
int string_fmt(char *s);
int percent_fmt(void);

#endif

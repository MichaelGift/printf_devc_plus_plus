#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
typedef struct FormatHandler
{
	char specifier;
	void (*handler)(va_list args);
}FormatHandler;

void handle_integer(va_list args);
void print_digits(int n);
void handle_unsigned_integer(va_list args);
int _printf(const char *format, ...);
int _putchar(char c);

#endif

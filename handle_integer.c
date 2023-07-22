#include <stdio.h>
#include <stdarg.h>
void handle_integer(va_list args)
{
	int i;
	int num = va_arg(args, int);
	
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	
	if (num  == 0)
	{
		_putchar('0');
		return;
	}

    print_digits(num);
}

/**
* print_digits - prints digits recursively
* @n: number to printed
*/
void print_digits(int n)
{
	if (n == 0)
        return;

    print_digits(n / 10);
    _putchar((n % 10) + '0');
}

#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

/**
* _printf - custom printf implementations
* @format: the specified format
* Return: number of chars printed
*/

int _printf(const char *format, ...)
{
	FormatHandler format_handlers[] = {
	{'d', handle_integer},
	{'i', handle_integer},
	};
	
	int i, len = 0, j;
	bool specifier_found =  false;
	va_list args;
	
	/* First check if the argumnent are null*/
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);	
	
	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		/*If format specifier is encountered check what comes next*/
		if (format[i] == '%')
		{
			/*Proceed to the next character and look to see if it a defined format handle*/
			
			i++;
			for (j = 0; j < sizeof(format_handlers); j++)
			{
				/*if it exists carry out the operation associated with the format*/
				if (format[i] == format_handlers[j].specifier)
				{
					format_handlers[j].handler(args);
					specifier_found = true;
					break;
				}
			}
			
			if (!specifier_found)
			{
				_putchar(format[i]);
			}
		}
		else
		{
			_putchar(format[i]);
		}
		len++;
	}
	
	va_end(args);
	return (len);
}

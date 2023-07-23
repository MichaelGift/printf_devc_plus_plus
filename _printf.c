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
		{'u', handle_unsigned_integer},
		{'c', handle_char},
		{'s', handle_string},
		{'o', handle_octal},
		{'x', handle_hexadecimal},
		{'X', handle_hexadecimal},
//		{'p', handle_pointer},
//		{'b', handle_binary},
//		{'r', handle_reverse},
//		{'R', handle_rot13},
//		{'S', handle_custom_S}
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
		specifier_found = false;
		/*If format specifier is encountered check what comes next*/
		if (format[i] == '%')
		{
			/*Proceed to the next character and look to see if it a defined format handle*/
			
			i++;
			
			Flags flags = {0};
			FlagMap flag_map[] = {
				{'+', &(flags.plus_flag)},
        		{' ', &(flags.space_flag)},
        		{'#', &(flags.hash_flag)},
        		{'-', &(flags.minus_flag)},
			};
			
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == 'h' || format[i] == 'l' || format[i] == '-' )
			{
				// Search the flag_map for the current flag character and set the flag if found
                for (j = 0; j < sizeof(flag_map) / sizeof(flag_map[0]); j++)
                {
                    if (format[i] == flag_map[j].flag_char)
                    {
                    	if (format[i] == 'h')
                    	{
                    		*(flag_map[j].flag_pointer) = 1;
                    		break;
						}
						
                    	if (format[i] == 'l')
                    	{
                    		*(flag_map[j].flag_pointer) = 2;
                    		break;
						}
                        *(flag_map[j].flag_pointer) = 1; // Set the flag using the flag pointer
//                        printf("%d", flags.minus_flag);
                        break;
                    }
                }
                i++;
			}
			int field_width = 0;
            while (isdigit(format[i]))
            {
                field_width = (field_width * 10) + (format[i] - '0');
                i++;
            }
            flags.field_width = field_width;
            int precision = -1; // Initialize to -1 to indicate that no precision is specified
			if (format[i] == '.')
			{
				i++; // Move to the next character after the period
				precision = 0;
				while (isdigit(format[i]))
				{
					precision = (precision * 10) + (format[i] - '0');
					i++;
				}
			}
			flags.precision = precision;
            
            int zero_flag = 0; // Initialize to 0 (false) to indicate that the 0 flag is not presen
			if (format[i] == '0')
			{
    			zero_flag = 1; // Set to 1 (true) if the 0 flag is present
    			i++; // Move to the next character
			}
			flags.zero_flag = zero_flag;

			for (j = 0; j < sizeof(format_handlers) / sizeof(format_handlers[0]); j++)
			{
				/*if it exists carry out the operation associated with the format*/
				if (format[i] == format_handlers[j].specifier)
				{
					format_handlers[j].handler(args, flags);
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

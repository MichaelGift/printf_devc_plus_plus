#ifndef PRINTF
#define PRINTF

#include <stdarg.h>

typedef struct Flags
{
	int plus_flag;
	int space_flag;
	int hash_flag;
	int zero_flag;
	int length_modifier;
	int field_width;
	int precision;
	int minus_flag;
}Flags;

typedef struct FlagMap
{
	char flag_char;
	int *flag_pointer;
}FlagMap;

typedef struct ConversionPrinter
{
	char specifier;
	void (*conversion_type)(va_list args);
} ConversionPrinter;

typedef struct FormatHandler
{
	char specifier;
	void (*handler)(va_list args, Flags flags);
}FormatHandler;

/*Integer handlers*/
void handle_integer(va_list args, Flags flags);
int length_flag_checker(va_list args, Flags flags);
void print_integer(int num, Flags flags);

/*Usigned integer handlers*/
void handle_unsigned_integer(va_list args, Flags flags);
void print_unsigned_integer(unsigned int num, Flags flags);

/*Char handlers*/
void handle_char(va_list args, Flags flags);
void print_char(int c, Flags flags);

/*String handlers*/
void handle_string(va_list args, Flags flags);

/* Octal handlers*/
void handle_octal(va_list args, Flags flags);
void print_octal(unsigned int num, Flags flags);

/*Hexadecimal Handlers*/
void handle_hexadecimal(va_list args, Flags flags);
void print_hexadecimal(unsigned int num, Flags flags);

/* Pointer Handler*/
void handle_pointer(va_list args, Flags flags);
//void print_pointer(int num, Flags flags);

/*Binary Handler*/
void handle_binary(va_list args, Flags flags);

/*Reverse handler*/
void handle_reverse(va_list args, Flags flags);

/*Rot13 handler*/
void handle_rot13(va_list args, Flags flags);

/*Handle Custom s*/
void handle_custom_S(va_list args, Flags flags);

/*Helper function*/
int calculate_field_width(int num);
void handle_width_flag(int num_width, Flags flags, int num, void (*specific_print_function)(int, Flags));

/*Main functions*/
int _printf(const char *format, ...);
int _putchar(char c);

#endif

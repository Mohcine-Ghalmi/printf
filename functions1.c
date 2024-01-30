#include "main.h"

/**
 * p_unsi - Prints an unsigned number
 * @data_type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int p_unsi(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	int i;
	unsigned long int num;

	num = 0;
	num = size_uns(num, size);
	num = va_arg(data_type, unsigned long int);
	i = BUFF_SIZE - 2;
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (p_usigned(0, i, buffer, flags, width, precision, size));
}

/**
 * p_oct - Prints an unsigned number in octal notation
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int p_oct(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{

	int i;
	unsigned long int num;
	unsigned long int init_num;

	UNUSED(width);
	num = va_arg(data_type, unsigned long int);
	init_num = num;
	i = BUFF_SIZE - 2;
	num = size_uns(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (p_usigned(0, i, buffer, flags, width, precision, size));
}

/**
 * p_hexa - Prints an unsigned number in hexadecimal notation
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int p_hexa(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hx(data_type, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * p_hexa_upp - Prints an unsigned number in upper hexadecimal notation
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int p_hexa_upp(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hx(data_type, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hx - Prints a hexadecimal number in lower or upper
 * @data_type: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hx(va_list data_type, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i;
	unsigned long int num;
	unsigned long int init_num;

	UNUSED(width);
	i = BUFF_SIZE - 2;
	num = va_arg(data_type, unsigned long int);
	init_num = num;
	num = size_uns(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (p_usigned(0, i, buffer, flags, width, precision, size));
}

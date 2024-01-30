#include "main.h"

/**
 * p_point - Prints the value of a pointer variable
 * @data_type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int p_point(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd;
	int ind, length, padd_start;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs;

	addrs = va_arg(data_type, void *);
	ind = BUFF_SIZE - 2;
	length = 2;
	padd = ' ';
	padd_start = 1;
	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (put_point(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * p_non_print - Prints ascii codes in hexa of non printable chars
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int p_non_print(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, offset;
	char *str;

	i = 0;
	offset = 0;
	str = va_arg(data_type, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += appn_hex(str[i], buffer, i + offset);

		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}

/**
 * p_rev - Prints reverse string.
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int p_rev(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count;

	count = 0;
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(data_type, char *);
	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++);
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * p_rot13str - Print a string in rot13.
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int p_rot13str(va_list data_type, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	count = 0;
	str = va_arg(data_type, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

#include "main.h"

/**
 * p_char - Prints a char
 * @data_type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @prec: prec specification
 * @sz: sz specifier
 * Return: Number of chars printed
 */
int p_char(va_list data_type, char buffer[],
	int flags, int width, int prec, int sz)
{
	char c;

	c = va_arg(data_type, int);
	return (hand_charr(c, buffer, flags, width, prec, sz));
}

/**
 * p_str - Prints a string
 * @data_type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @prec: prec specification
 * @sz: sz specifier
 * Return: Number of chars printed
 */
int p_str(va_list data_type, char buffer[],
	int flags, int width, int prec, int sz)
{
	int length, i;
	char *str;

	length = 0;
	str = va_arg(data_type, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (prec >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prec >= 0 && prec < length)
		length = prec;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * p_prec - Prints a percent sign
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @prec: prec specification
 * @sz: sz specifier
 * Return: Number of chars printed
 */
int p_prec(va_list data_type, char buffer[],
	int flags, int width, int prec, int sz)
{
	UNUSED(data_type);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(sz);
	return (write(1, "%%", 1));
}

/**
 * p_int - Print int
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @prec: prec specification
 * @sz: sz specifier
 * Return: Number of chars printed
 */
int p_int(va_list data_type, char buffer[],
	int flags, int width, int prec, int sz)
{
	int i;
	int is_negative;
	long int n;
	unsigned long int num;

	n = 0;
	n = size_num(n, sz);
	i = BUFF_SIZE - 2;
	n = va_arg(data_type, long int);
	is_negative = 0;
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (p_nbr(is_negative, i, buffer, flags, width, prec, sz));
}

/**
 * p_bin - Prints an unsigned number
 * @data_type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @prec: prec specification
 * @sz: sz specifier
 * Return: Numbers of char printed.
 */
int p_bin(va_list data_type, char buffer[],
	int flags, int width, int prec, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(sz);

	n = va_arg(data_type, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

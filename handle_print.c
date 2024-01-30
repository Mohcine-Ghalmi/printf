#include "main.h"
/**
 * take_widthhd_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int take_widthhd_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len, printed_chars;
	fmt_t fmt_types[] = {
		{'c', p_char}, {'s', p_str}, {'%', p_prec},
		{'i', p_int}, {'d', p_int}, {'b', p_bin},
		{'u', p_unsi}, {'o', p_oct}, {'x', p_hexa},
		{'X', p_hexa_upp}, {'p', p_point}, {'S', p_non_print},
		{'r', p_rev}, {'R', p_rot13str}, {'\0', NULL}
	};

	unknow_len = 0;
	printed_chars = -1;
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

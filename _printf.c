#include "main.h"

/**
 * printf_filling - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_idx: Index at which to add next char, represents the length.
 */
void printf_filling(char buffer[], int *buff_idx)
{
	if (*buff_idx > 0)
		write(1, &buffer[0], *buff_idx);
	*buff_idx = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: count chars.
 */
int _printf(const char *format, ...)
{
	int i, count, count_chars;
	int flags, width, precision, size, buff_idx;
	va_list list;
	char buffer[BUFF_SIZE];

	count = 0;
	count_chars = 0;
	buff_idx = 0;
	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_idx++] = format[i];
			if (buff_idx == BUFF_SIZE)
				printf_filling(buffer, &buff_idx);
			count_chars++;
		}
		else
		{
			printf_filling(buffer, &buff_idx);
			flags = take_flag(format, &i);
			width = take_width(format, &i, list);
			precision = take_prec(format, &i, list);
			size = take_size(format, &i);
			++i;
			count = take_widthhd_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (count == -1)
				return (-1);
			count_chars += count;
		}
	}
	printf_filling(buffer, &buff_idx);
	va_end(list);
	return (count_chars);
}

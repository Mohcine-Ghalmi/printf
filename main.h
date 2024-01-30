#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int take_widthhd_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int p_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_prec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_unsi(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_hexa_upp(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hx(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int p_non_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_point(va_list data_type, char buffer[],
	int flags, int width, int precision, int size);
int take_flag(const char *format, int *i);
int take_width(const char *format, int *i, va_list list);
int take_prec(const char *format, int *i, va_list list);
int take_size(const char *format, int *i);
int p_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int p_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hand_charr(char c, char buffer[],
	int flags, int width, int precision, int size);
int p_nbr(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int put_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int put_point(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int p_usigned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
int is_print(char);
int appn_hex(char, char[], int);
int is_digit(char);
long int size_num(long int num, int size);
long int size_uns(unsigned long int num, int size);

#endif

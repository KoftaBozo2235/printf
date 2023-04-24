#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * p_unsigned - Prints an unsigned number
 * @args: List a of arguments
 * @buf: Buffer array to handle print
 * @flg:  Calculates active flags
 * @fld_wid: get width
 * @pre: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int p_unsigned(va_list args, char buf[], int flg, int fld_wid, int pre, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	number = convert_size_unsgnd(number, sz);

	if (number == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buf[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buf, flg, fld_wid, pre, sz));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * p_octal - Prints an unsigned number in octal notation
 * @typ: Lista of arguments
 * @buf: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int p_octal(va_list typ, char buf[],
	int flg, int wid, int pre, int sz)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flg & F_HASH && init_num != 0)
		buf[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buf, flg, wid, pre, sz));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * p_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @typ: Lista of arguments
 * @buf: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int p_hexadecimal(va_list typ, char buf[],
	int flg, int wid, int pre, int sz)
{
	return (print_hexa(typ, "0123456789abcdef", buf,
		flg, 'x', wid, pre, sz));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * p_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @typ: Lista of arguments
 * @buf: Buffer array to handle print
 * @flg:  Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int p_hexa_upper(va_list typ, char buf[],
	int flg, int wid, int pre, int sz)
{
	return (print_hexa(typ, "0123456789ABCDEF", buf,
		flg, 'X', wid, pre, sz));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * p_hexa - Prints a hexadecimal number in lower or upper
 * @typ: Lista of arguments
 * @map: Array of values to map the number to
 * @buf: Buffer array to handle print
 * @flg:  Calculates active flags
 * @flg_ch: Calculates active flags
 * @wid: get width
 * @pre: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int p_hexa(va_list typ, char map[], char buf[],
	int flg, char flg_ch, int wid, int pre, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wid);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flg & F_HASH && init_num != 0)
	{
		buf[i--] = flg_ch;
		buf[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buf, flg, wid, pre, sz));
}

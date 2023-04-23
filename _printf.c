#include "main.h"
int _printf (const char *format, ...)
{
	va_list args;
	int i = 0;
	char *string;
	char my_char;
	char thing = '%';
	va_start(args, format);

	while (format[i])
	{
	if (format[i] == '%')
			{
			if (format[i+1] == 's')
			{

		string = va_arg(args, char*);
		write(1, string, strlen(string));
		i++;
		}
			else if (format[i+1] == 'c')
			{
				my_char = va_arg(args, int);
				write(1, &my_char, 1);
				i++;
			}
			else if (format[i+1] == '%')
			{
				my_char = va_arg(args, int);
				write(1, &thing, 1);
				i++;
			}

		}
	else
	{
		_putchar(format[i]);
	}
	i++;
	}
	return (0);
}	

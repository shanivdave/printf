#include"main.h"
#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>



/**
 * get_spec - get the format
 * @format: type of specifier
 *
 * Return: NULL or valid function
 */

int (*get_spec(const char *format))(va_list)
{
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};
	int i;

	for (i = 0; p[i].type != NULL; i++)
	{
		if (*(p[i].type) == *format)
			break;
	}
	return (p[i].func);
}

/**
 * _printf - function print all
 * @format: type of the argument
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, n = 0;
	va_list list;
	int (*sp)(va_list);

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		for (; format[i] && format[i] != '%'; i++)
		{
			_putchar(format[i]);
			n++;
		}
		if (format[i] == '\0')
			return (n);

		sp = get_spec(&format[i + 1]);
		if (sp != NULL)
		{
			n += sp(list);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		n++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(list);
	return (n);
}




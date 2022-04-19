#include "main.h"

/**
 * _typefor - struct of format specifiers.
 * @argu: arguments passed.
 * @argb: position.
 * Return: 0.
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

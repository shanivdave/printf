#include "main.h"
/**
 * get_flag - turns on flags if _printf finds
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flags(char c, han_s *f)
{
	int i = 0;

	switch (c)
	{
	case '+':
		(*f).plus = 1;
		i = 1;
		break;
	case ' ':
		(*f).space = 1;
		i = 1;
		break;
	case '#':
		(*f).hash = 1;
		i = 1;
		break;
	case '-':
		(*f).minus = 1;
		i = 1;
		break;
	case '0':
		(*f).zero = 1;
		i = 1;
		break;
	}
	return (i);
}



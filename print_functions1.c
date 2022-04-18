#include "main.h"

/**
 * _rot13 - function that converts a string to rot13
 * @ap: argument pointer to take arguments from.
 * Return: the counter of the string.
 */
int _rot13(va_list ap)
{
	int i, j, counter = 0;
	int f = 0;
	char *s = va_arg(ap, char*);
	char a[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char b[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		f = 0;
		for (j = 0; a[j] && !f; j++)
		{
			if (s[i] == a[j])
			{
				_putchar(b[j]);
				counter++;
				f = 1;
			}
		}
		if (!f)
		{
			_putchar(s[i]);
			counter++;
		}
	}
	return (counter);
}
/**
 * _printrev - prints a string, in reverse
 * @ap: argument pointer to take arguments from
 *
 * Return: the counter of the string
 */
int _printrev(va_list ap)
{

	char *s = va_arg(ap, char*);
	int c;
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
		i++;
	for (c = i - 1; c >= 0; c--)
		_putchar(s[c]);
	return (i);
}

#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - print a formatted text
 * @format: str with the text and format
 * Return: the number of bytes that print
 */

int _printf(const char *format, ...)
{

	int bytes = 0, bts = 0;
	char *head, *current, *init, *buffer, *copy;
	int (*execute)(va_list ap, char **buffer);
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);
	current = head = init = (char *) format;

	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
		return (-1);
	copy = buffer;

	while (*head)
	{
		if (*head == '%' || *current == '%')
		{
			if (*current != '%')
				current = head;

			if (*(head + 1) == 32 || *(head + 1) == 9)
			{
				head++;
				continue;
			}
			execute = get_ops_function(*(head + 1), &buffer, &bytes);
			bts = execute(ap, &buffer);
			current = init;
			buffer += bts, bytes += bts;
			head += 2;
		}
		else
			*buffer++ = *head++, bytes++;
	}

	buffer = copy;
	write(1, buffer, bytes);
	free(buffer);
	va_end(ap);
	printf("%d\n", bytes);
	return (bytes);
}





#include "shell.h"

/**
 * _strcmp - compares two strings
 * @dest: first string.
 * @src: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */
int _strcmp(char *dest, char *src)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(dest + i) == '\0') && (*(src + i) == '\0'))
			break;
		op = *(dest + i) - *(src + i);
		i++;
	}

	return (op);
}

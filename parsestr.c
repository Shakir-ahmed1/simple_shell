#include "shell.h"

/**
 * parse_str - tokenize the given string
 * @str: the string to be parsed
 *
 * Return: parsed string
 * if it failes return null
 */

char **parse_str(char *str)
{
	char *stkn;
	char **arr;
	int i;

	arr = malloc(sizeof(char *) * SIZEOFPARSE_STR);
	if (!arr)
		exit(EXIT_FAILURE);
	stkn = strtok(str, DELIM);
	arr[0] = stkn;
	i = 1;
	while (stkn != NULL)
	{
		stkn = strtok(NULL, DELIM);
		arr[i] = stkn;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

#include "main.h"

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

	stkn = strtok(str, " \n");
	arr = malloc(sizeof(char *) * SIZEOFPARSE_STR);
	if (!arr)
		return (NULL);

	arr[0] = stkn;
	i = 1;
	while (stkn != NULL)
	{
		stkn = strtok(NULL, " \n");
		arr[i] = stkn;
		i++;
	}
	return (arr);
}

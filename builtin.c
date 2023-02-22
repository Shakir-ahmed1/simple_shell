#include "main.h"

/**
 * _bexit - exits the loop
 *
 * Return: 0
 */

int _bexit(void)
{
	exit(98);
	return (0);

}

/**
 * _benv - prints environmental variable
 *
 * Return: one
 */

int _benv(void)
{
	int k = 0;

	while (environ[k] != NULL)
	{
		printf("%s\n", environ[k]);
		k++;
	}
	return (1);
}
/**
 * mystrtok - it extracts string by spliting the string using the delimiter
 * @d: the delimiter used to split
 * @s: the source's string. it should only called passed once to the string
 * and if more extraction is to be performed, NULL must be passed
 *
 * Return: the splited string
 */
char *_strtok(char *s, char *d)
{
	static char *input;
	char *result;
	int i = 0, j = 0, len_d = 0;
	while(d[len_d])
		len_d++;

	if (s != NULL)
		input = s;
	if (input == NULL)
		return (NULL);
	result = malloc(sizeof(input) + 1);
	if (result == NULL)
		return (NULL);
	for (; input[i] != '\0'; i++)
	{
		for (j = 0; j < len_d; j++)
		{
			if (input[i + j] != d[j])
				break;
		}
		if (j < len_d)
		{
			result[i] = input[i];
		}
		else
		{
		result[i] = '\0';
		input = input + i + j;
		return (result);
		}
	}
	result[i] = '\0';
	input = NULL;
	return (result);
}


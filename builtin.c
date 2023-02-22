#include "main.h"

/**
 * _bexit - exits the loop
 *
 * Return: 0
 */

int _bexit(void)
{
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

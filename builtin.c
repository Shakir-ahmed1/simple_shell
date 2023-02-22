#include "shell.h"

/**
 * _exit_shell - exits the loop
 *
 * Return: 0
 */
int _exit_shell(void)
{
	return (0);
}

/**
 * _print_env - prints environmental variable
 *
 * Return: one
 */

int _print_env(void)
{
	int k = 0;

	while (environ[k] != NULL)
	{
		printf("%s\n", environ[k]);
		k++;
	}
	return (1);
}

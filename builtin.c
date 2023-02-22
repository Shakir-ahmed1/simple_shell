#include "main.h"

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
		write(STDOUT_FILENO, environ[k], _strlen(environ[k]));
		k++;
	}
	return (1);
}

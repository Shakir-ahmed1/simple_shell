#include "main.h"

/**
 * _execute - execute commands given
 * @arg: command to be given
 * @argv: command line argument
 *
 * Return: nothing
 */

void _execute(char **arg, char **argv)
{
	pid_t my_pid;
	int status;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (my_pid == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

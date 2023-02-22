#include "shell.h"

/**
 * main - check the code
 * @ac: number of arguments
 * @argv: argument vector
 * @env: enviromental variable
 *
 * Return: Always 0
 */


int main(int ac __attribute__((unused)), char **argv, char **env)
{
	size_t len = 0;
	int status;
	char *command = NULL;
	char **arr;

	signal(SIGINT, sig_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&command, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (command == NULL)
			exit(EXIT_FAILURE);
		arr = parse_str(command);
		if (!arr[0])
		{
			free(arr);
			continue;
		}
		status = check_builtin(arr);
		if (status == 0)
		{
			free(command);
			free(arr);
			return (0);
		}
		_execute(arr, argv, env);
	}
	free(command);
	return (0);
}

/**
 * sig_handler - handles the SIGINT interrupt signal
 * @signum: signal id
 *
 */

void sig_handler(int signum)
{
	(void) signum;

	write(STDOUT_FILENO, "\n", 0);
}

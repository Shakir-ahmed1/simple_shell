#include "main.h"

/**
 * main - check the code
 * @ac: number of arguments
 * @argv: argument vector
 * @env: enviromental variable
 *
 * Return: Always 0
 */

int main(int ac, char **argv, char **env)
{
	size_t len = 0;
	int status;
	char *command = NULL;
	char **arr;

	signal(SIGINT, sig_handler);
	while (1)
	{
		printf("$ ");
		if (getline(&command, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (!command)
			exit(EXIT_SUCCESS);
		arr = parse_str(command);
		status = check_builtin(arr);
		if (status == 0)
			return (0);
		_execute(arr, argv);
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

	write(STDOUT_FILENO, "\n", 1);
}

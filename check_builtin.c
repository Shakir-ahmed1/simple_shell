#include "main.h"

/**
 * check_builtin - checks whether the given command is builtin
 * or not
 * @arr: command given
 *
 * Return: if the command is exit it returns 0
 * else return 1
 */

int check_builtin(char **arr)
{
	char *builtin_cmd[] = {"exit", "env"};
	int (*builtin_fun[])() = {_bexit, _benv};
	int i, status;
	char *exstat = "98";

	for (i = 0; i < NUMBUILTIN_CMD; i++)
	{
		if ((_strcmp(builtin_cmd[i], arr[0]) == 0) &&
		    ((arr[1] == NULL || (arr[1] == exstat && arr[2] == NULL))))
			status = (*builtin_fun[i])();
	}
	if (status != 0)
		return (1);
	return (0);
}

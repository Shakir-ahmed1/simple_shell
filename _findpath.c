#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * char_counter - counts the given character in the string
 * @str: the string
 * @c: the char to be counted
 * Return: the counted characters
 */
int char_counter(char *str, char c)
{
	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			j++;
		}
		i++;
	}
	return (j);
}
/**
 * join_3 - joins three charcters to one
 * @a: first string
 * @b: second string
 * @d: third string
 * Return: the joined string
 */
char *join_3(char a[], char b[], char d[])
{
	size_t i = 0;
	char *c;

	c = malloc((strlen(a) + strlen(b) + strlen(d) + 1) * sizeof(char));
	if (!c)
		return (NULL);
	for (; i < strlen(a); i++)
		c[i] = a[i];
	for (; i < strlen(b) + strlen(a); i++)
		c[i] = b[i - strlen(a)];
	for (; i < strlen(d) + strlen(b) + strlen(a); i++)
		c[i] = d[i - strlen(a) - strlen(b)];
	c[i] = '\0';
	free(a);
	return (c);
}
/**
 * mystrtok - it extracts string by spliting the string using the delimiter
 * @d: the delimiter used to split
 * @s: the source's string. it should only called passed once to the string
 * and if more extraction is to be performed, NULL must be passed
 * Return: the splited string
 */
char *mystrtok(char *s, char *d)
{
	static char *input;
	char *result;
	int i = 0;

	if (s != NULL)
		input = s;
	if (input == NULL)
		return (NULL);
	result = malloc(strlen(input) + 1);
	for (; input[i] != '\0'; i++)
	{
		if (input[i] != d[0])
		{
			result[i] = input[i];
		}
		else
		{
		result[i] = '\0';
		input = input + i + 1;
		return (result);
		}
	}
	result[i] = '\0';
	input = NULL;
	return (result);
}
/**
 * _find_pathdir - finds the PATH and appends the given command
 * @arr: the passed argument
 * @argv: the second argument
 */
void _find_pathdir(char **arr, char **argv)
{
	int i = 0, k = 0, count;
	char *str, *stkn;
	char *parsedir[1024];

	(void) argv;
	str = getenv("PATH");
	count = char_counter(str, ':');
	stkn = join_3(mystrtok(str, ":"), "/", arr[0]);
	parsedir[0] = stkn;
	printf("%s\n", parsedir[0]);
	while (k < count)
	{
		stkn = join_3(mystrtok(NULL, ":"), "/", arr[0]);
		parsedir[++i] = stkn;
		if (stkn != NULL)
			printf("%s\n", parsedir[i]);
		k++;
	}
	k = 0;
	while (k <= count)
	{
		free(parsedir[k]);
		k++;
	}
}
/**
 * main - entry
 * Return: always 0
 */
int main(void)
{
	char *arr[] = {"ls", NULL};
		_find_pathdir(arr, NULL);
		return (0);
}

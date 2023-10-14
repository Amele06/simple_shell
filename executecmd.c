#include "shell.h"
#include <limits.h>
/**
*is_digit - a function that check if a string is a number
*@prt: string to be checked
*Return: always 0
*/
int is_digit(const char *prt)
{
	unsigned int j;

	for (j = 0; prt[j]; j++)
	{
		if (prt[j] < 48 || prt[j] > 57)
			return (0);
	}
	return (1);
}

/**
*exit_cmds - a function that get out of a simple shell
*@av: name of the programme
*@ptr: pointer to a character
*@_exit: exit cmd
*@args: an argument
*Return: always void
*/

void exit_cmds(char *av, char **args, char *ptr, int _exit)
{
	int exit_stat = 0, digits, length, number;

	if (!args[1])
	{
		free(ptr);
		free(args);
		exit(_exit);
	}
	exit_stat = atoi(args[1]);
	digits = is_digit(args[1]);
	length = _strlen(args[1]);
	number = exit_stat > INT_MAX;
	if (!digits || length > 10 || number)
	{
		fprintf(stderr, "%s: 1: %s: Illegal number: %s\n", av, args[0], args[1]);
		free(ptr);
		free(args);
		exit(2);
	}

	free(ptr);
	free(args);
	exit(exit_stat % 256);
}

/**
*_getenviron - gets environment variables
*@env : contains env variables
*Return : always void
*/
void _getenviron(char **env)
{
	size_t j = 0;

	while (env[j])
	{
		write(STDOUT_FILENO, env[j], _strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

/**
*_getpath - function that finds the PATH of a variable
*@environ: contains env variables
*Return: return path to the variable
*/
char *_getpath(char **environ)
{
	size_t var, j, c;
	char *path = NULL;

	for (j = 0; _strncmp(environ[j], "PATH", 5); j++)
	{};
	if (environ[j] == NULL)
		return (NULL);
	for (c = 5; environ[j][var]; var++, c++)
	{};
	path = malloc(sizeof(char) * (c + 1));

	if (path == NULL)
		return (NULL);
	for (var = 5, c = 0; environ[j][var]; var++, c++)
		path[c] = environ[j][var];
	path[c] = '\0';
	return (path);
}

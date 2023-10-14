#include "shell.h"

/**
 * _fork - function that diverges processes
 * @d: add test
 * @av: argument variables
 * @args: arguments
 * @str: user's command
 * @id: process identification
 * @env: environment variable
 * Return: 0 (always on success)
 */

int _fork(char **args, char **av, char **env, char *str, int id, int d)
{
	pid_t child;
	int status;
	char *data = "%s: %d: %s: not found\n";

	child = fork();

	if (child == -1)
	{
		perror("fork failed");
		return (-1);
	}
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, data, av[0], id, args[0]);
			if (!d)
				free(args[0]);
			free(args);
			free(str);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}

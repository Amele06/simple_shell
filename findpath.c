#include "shell.h"

/**
*pathfind - contains the PATH to environment variables
*@args: arguments
*@environ: contains environment variables
*Return: PATH
*/

int pathfind(char **args, char **environ)
{
	char *tokz = NULL, *full_path = NULL, *path_t = NULL;
	size_t v, cmd;
	struct stat stat_ptr;

	if (stat(*args, &stat_ptr) == 0)
		return (-1);
	path_t = _getpath(environ);
	if (!path_t)
		return (-1);
	tokz = _strtok(path_t, ":");
	cmd = _strlen(*args);
	while (tokz)
	{
		v = _strlen(tokz);
		full_path = malloc(sizeof(char) * (v + cmd + 2));
		if (!full_path)
		{
			*args = full_path;
			free(path_t);
			return (0);
		}
		free(full_path);
		tokz = _strtok(NULL, ":");
	}
	free(path_t);
	return (-1);
}

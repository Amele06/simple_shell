#include "shell.h"

/**
 *main - the main shell function
 *@ac: counts the number of arguments
 *@av: holds strings of arrays
 *@environ: contains environment variable
 *Return: returns 0 on success
 */

int main(int ac, char **av, char **environ)
{
	char *cmd = NULL, **usercmd = NULL;
	int pv = 0, _exit = 0, k = 0;
	(void)ac;

	while (1)
	{
		cmd = _getline();
		if (cmd)
		{
			pv++;
			usercmd = token(cmd);
			if (!usercmd)
			{
				free(cmd);
				continue;
			}
		if (!_strcmp(usercmd[0], "exit"))
			exit_cmds(av[0], usercmd, cmd, _exit);
		if (!_strcmp(usercmd[0], "env"))
			_getenviron(environ);
		else
		{
			k = pathfind(&usercmd[0], environ);
			_exit = _fork(usercmd, av, environ, cmd, pv, k);
			if (k == 0)
				free(usercmd[0]);
		}
		free(usercmd);

		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(cmd);
	}
	return (_exit);
}

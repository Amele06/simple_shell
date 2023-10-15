#include "shell.h"

/**
 *main - shell function
 *@ac: counts the number of argumentsin a variable
 *@av: holds strings of array
 *@environ: contains environment variable
 *Return: returns 0 on success
 */

int main(int ac, char **av, char **environ)
{
	char *cmds = NULL, **usercmd = NULL;
	int p = 0, _exit = 0, u = 0;
	(void)ac;

	while (1)
	{
		cmds = _getline();
		if (cmds)
		{
			p++;
			usercmd = token(cmds);
			if (!usercmd)
			{
				free(cmds);
				continue;
			}
		if (!_strcmp(usercmd[0], "exit"))
			exit_cmds(av[0], usercmd, cmds, _exit);
		if (!_strcmp(usercmd[0], "env"))
			_getenviron(environ);
		else
		{
			u = pathfind(&usercmd[0], environ);
			_exit = _fork(usercmd, av, environ, cmds, p, u);
			if (u == 0)
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
		free(cmds);
	}
	return (_exit);
}

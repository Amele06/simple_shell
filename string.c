#include "shell.h"

/**
*token - a function that gets string token
*@ptr: receives a pointer
*Return: return strings
*/

char **token(char *ptr)
{
	char **cmds = NULL;
	char *token = NULL;
	size_t i = 0;
	int j = 0;

	if (ptr == NULL)
		return (NULL);
	for (i = 0; ptr[i]; i++)
	{
		if (ptr[i] == ' ')
			j++;
	}
	if ((j + 1) == _strlen(ptr))
		return (NULL);
	cmds = malloc(sizeof(char *) * (j + 2));
	if (cmds == NULL)
		return (NULL);
	token = _strtok(ptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		cmds[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	cmds[i] = NULL;
	return (cmds);
}

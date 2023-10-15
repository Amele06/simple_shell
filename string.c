#include "shell.h"

/**
*token - a function that gets tokenized string
*@ptr: receives a pointer to a string
*Return: return string
*/

char **token(char *ptr)
{
	char **cmds = NULL;
	char *token = NULL;
	size_t a = 0;
	int j = 0;

	if (ptr == NULL)
		return (NULL);
	for (a = 0; ptr[a]; a++)
	{
		if (ptr[a] == ' ')
			j++;
	}
	if ((j + 1) == _strlen(ptr))
		return (NULL);
	cmds = malloc(sizeof(char *) * (j + 2));
	if (cmds == NULL)
		return (NULL);
	token = _strtok(ptr, " \n\t\r");
	for (a = 0; token != NULL; a++)
	{
		cmds[a] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	cmds[a] = NULL;
	return (cmds);
}

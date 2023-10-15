#include "shell.h"

/**
*_strchar - find the first appearnce of c
*@str: string receive
*@ch: characters to the string
*Return: a pointer
*/
char *_strchar(const char *str, int ch)
{
	while (*str != (char)ch)
		if (!*str++)
			return (0);
	return ((char *)str);
}
/**
*_strsp - finds the max length of a string
*@str1: string to find the max length
*@str2: string containing delimiters
*Return: length
*/
size_t _strsp(const char *str1, const char *str2)
{
	size_t t = 0;

	while (*str1 && _strchar(str2, *str1++))
		t++;
	return (t);
}

/**
*_strcsp - finds the length of the max length of a string/arguments
*@str1: string to find its max length
*@str2: string for comparism
*Return: length
*/
size_t _strcsp(const char *str1, const char *str2)
{
	size_t t = 0;

	while (*str1)
	{
		if (_strchar(str2, *str1))
			return (t);
		str1++;
		t++;
	}
	return (t);
}

/**
*_strtok - a function that tokenizes strings
*@str: string to be tokenized
*@delimiter: characters to be used for tokenization of strings
*Return: tokenized string
*
*/
char *_strtok(char *str, const char *delimiter)
{
	static char *j;

	if (str)
		j = str;
	else if (!j)
		return (0);
	str = j + _strsp(j, delimiter);
	j = str + _strcsp(str, delimiter);
	if (j == str)
		return (j = 0);
	j = *j ? *j = 0, j + 1 : 0;
	return (str);
}

/**
*_strlen - length of a string
*@str: string to be returned
*Return: length of the string
*/
int _strlen(char *str)
{
	int u;
	int number = 0;

	for (u = 0; str[u] != '\0'; u++)
		number++;
	return (number);
}

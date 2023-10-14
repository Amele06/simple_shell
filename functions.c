#include "shell.h"

/**
*_strchar - find the first appearnce of c
*@s: string receive
*@ch: characters to the string
*Return: a pointer
*/
char *_strchar(const char *s, int ch)
{
	while (*s != (char)ch)
		if (!*s++)
			return (0);
	return ((char *)s);
}
/**
*_strsp - finds the max length of a string
*@s1: string to find the max length
*@s2: string containing delimiters
*Return: length
*/
size_t _strsp(const char *s1, const char *s2)
{
	size_t t = 0;

	while (*s1 && _strchar(s2, *s1++))
		t++;
	return (t);
}

/**
*_strcsp - finds the length of the max length of a string/arguments
*@s1: string to find its max length
*@s2: string for comparism
*Return: length
*/
size_t _strcsp(const char *s1, const char *s2)
{
	size_t t = 0;

	while (*s1)
	{
		if (_strchar(s2, *s1))
			return (t);
		s1++;
		t++;
	}
	return (t);
}

/**
*_strtok - a function that tokenizes the supplied token
*@str: string to be tokenized
*@delimiter: characters that separate strings
*Return: tokens
*
*/
char *_strtok(char *str, const char *delimiter)
{
	static char *i;

	if (str)
		i = str;
	else if (!i)
		return (0);
	str = i + _strsp(i, delimiter);
	i = str + _strcsp(str, delimiter);
	if (i == str)
		return (i = 0);
	i = *i ? *i = 0, i + 1 : 0;
	return (str);
}

#include "shell.h"

/**
 * _strcpy - copies the string pointed to by dep
 * @arr: copy destination
 * @dep: copy source
 * Return: string
 */

char *_strcpy(char *dep, char *arr)
{
	int i = 0;
	int j = 0;

	while (*(dep + 1) != '\0')
	{
		i++;
	}
	for ( ; j < i ; j++)
	{
		arr[j] = dep[j];
	}
	arr[i] = '\0';
	return (arr);
}

/**
 * _strcat - appends the dep string to the arr string
 * @dep: source string
 * @arr: destination string
 * Return: arr
 */

char *_strcat(char *arr, char *dep)
{
	int arrlen = 0;
	int deplen = 0;
	int i;

	for (i = 0 ; arr[i] != '\0' ; i++)
		arrlen++;
	for (i = 0 ; dep[i] != '\0' ; i++)
		deplen++;
	for (i = 0 ; i <= deplen ; i++)
		arr[arrlen + i] = dep[i];
	return (arr);
}

/**
 * _strcmp - function that compares two string values
 * @str1: first string to compare
 * @str2: second string to compare
 * Return: str1[i] - str2[i]
 */

int _strcmp(char *str1, char *str2)
{
	int j;

	j = 0;
	while (str1[j] != '\0' && str2[j] != '\0')
	{
		if (str1[j] != str2[j])
		{
			return (str1[j] - str2[j]);
		}
		j++;
	}
	return (0);
}

/**
 * _strncat - function that concatenates two strings
 * @B: destination string
 * @A: source string
 * @num: number of bytes to concatenate
 * Return: B
 */

char *_strncat(char *A, char *B, int num)
{
	int x;
	int y;

	x = 0;
	while (B[x] != '\0')
	{
		x++;
	}
	y = 0;
	while (y < num && A[y] != '\0')
	{
		B[x] = A[y];
		x++;
		y++;
	}
	B[x] = '\0';
	return (B);
}

/**
*_strncmp - it compares strings
*@s1: first string
*@s2: second string
*@c: counts the number ofcharacter
*Return: always (zero)
*/
size_t _strncmp(char *s1, char *s2, size_t c)
{
	size_t a, b;

	for (b = 0; s1[b] != '\0' && b < c; b++)
	{
		a = s1[b] - s2[b];

		if (a != 0)
		{
			return (a);
		}
	}
	return (0);
}

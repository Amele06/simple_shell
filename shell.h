#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <limits.h>

extern char **environ;

int _strlen(char *str);
char *_strcpy(char *dep, char *arr);
char *_strcat(char *arr, char *dep);
int _strcmp(char *str1, char *str2);
size_t _strncmp(char *s1, char *s2, size_t c);
char *_strncat(char *A, char *B, int num);
int _fork(char **args, char **av, char **env, char *str, int id, int d);
char *_getline(void);
char *_strtok(char *str, const char *delimiter);
int pathfind(char **args, char **environ);
char **token(char *ptr);
int main(int ac, char **av, char **environ);
int is_digit(const char *prt);
void exit_cmds(char *av, char **args, char *ptr, int _exit);
void _getenviron(char **env);
char *_getpath(char **environ);

#endif

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

int _strlen(char *str);
char *_strcpy(char *dep, char *arr);
char *_strcat(char *arr, char *dep);
int _strcmp(char *str1, char *str2);
char *_strncat(char *A, char *B, int num);
int _fork(char **args, char **av, char **env, char *str, int id, int d);
char *_getline(void);

#endif

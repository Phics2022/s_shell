#pragma once
#include "phics.h"
extern char **environ;
ssize_t _getline(char **ptr, size_t *n, FILE *stream);
char *_strcat(char *s1, char *s2);
void _strtok(char *command, char *arg[]);

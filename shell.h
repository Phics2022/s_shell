#pragma once
extern char **environ;
char *_getenv(const char *name);
extern char **environ;
void handle_path(char *args, char *ag);
void handle_pid(pid_t pid, char *args[], char **av, char *command);
int handle_commands(char *args[]);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

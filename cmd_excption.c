#include "header.h"
#include "shell.h"
/**
  *handle_commands - handle the exceptional commands
  *args: command array
  *
  *Return: int 0 or 1
  */
int handle_commands(char *args[])
{
	char *val = malloc(sizeof(char) * 21);
	int i;
	i = atoi(val);
	if(strcmp(args[0], "exit") == 0)
	{
		free(val);
		exit(i);
	}
	return (0);
}

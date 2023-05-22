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
	int exit_status;
	if(strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			exit_status = atoi(args[1]);
			exit(exit_status);
		}
		exit(EXIT_SUCCESS);
	}
	return (0);
}

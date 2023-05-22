#include "header.h"
#include "shell.h"
/**
  *handle_pid - handle the fork statement
  *@pid: pid
  *@args: command
  *@av: vector
  *
  *Return: void
  */
void handle_pid(pid_t pid, char *args[], char **av, char *command)
{
	char **env = environ;
	if (pid == 0)
	{
		execve(args[0], args, env);
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	else if(pid < 0)
	{
		perror(av[0]);
		free(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

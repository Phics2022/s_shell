#include "header.h"
#include "shell.h"
/**
  *main - create the shell program
  *@ac - number of arguments
  *@av - vector
  *
  *Return: 0
  */
int main(__attribute__((unused)) int ac, char **av)
{
	int interactive, loop = 0;
	char *command = NULL, *args[256], *delim = " \n";
	size_t com_int = 0;
	pid_t pid;
	char ag[256];
	while(1)
	{
		if ((interactive = isatty(fileno(stdin))))
		{
			write(1, "$ ", 2);
			fflush(stdout);
		}
		if (getline(&command, &com_int, stdin) == -1)
			return (0);
		args[loop] = strtok(command, delim);
		if (args[loop] == NULL)
			continue;
		while (args[loop] != NULL)
		{
			loop++;
			args[loop] = strtok(NULL, delim);
		}
		args[loop] = NULL;
		handle_commands(args);
		loop = 0;
		handle_path(args[0], ag);	
		if((access(ag, X_OK | F_OK)) == -1)
		{
			perror(av[0]);
			continue;
		}
		args[0] = ag;
		pid = fork();
		handle_pid(pid, args, av, command);
		}
	free(command);
	return (0)
;
}

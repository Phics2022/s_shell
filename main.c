#include "phics.h"
#include "main.h"

/**
 * main - run simple shell
 * @ac: number of args
 * @av: executor
 *
 * Return: 0
 */
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	int status;
	bool is_trm = isatty(fileno(stdin));
	int start = 1;
	char *command = NULL;
	size_t input;
	char *arg[100];
	ssize_t checker;
int execute;
pid_t pid;
while (start)
{
if (is_trm)
{
printf("$ ");
fflush(stdout);
}
checker = _getline(&command, &input, stdin);
if (checker == -1)
	break;
_path_finder(command, arg);
pid = fork();
if (pid == 0)
{
	execute = execve(arg[0], arg, env);
	if (execute == -1)
	{
		perror(av[0]);
		exit(1);
	}
}
else if (pid < 0)
{
	perror(av[0]);
}
else
{
wait(&status);
}
}
free(command);
return (0);
}

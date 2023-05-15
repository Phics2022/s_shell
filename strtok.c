#include "phics.h"
#include "main.h"
/**
 * _strtok - tokenise command
 * @command: command
 * @arg: tokenised command
 *
 * Return: void
 */
void _strtok(char *command, char *arg[])
{
int loop = 0;
arg[loop] = strtok(command, " \n");
while (arg[loop] != NULL)
{
	loop++;
	arg[loop] = strtok(NULL, " \n");
}
arg[loop] = NULL;
if (loop > 1)
	arg[0] = "feranmi";
}

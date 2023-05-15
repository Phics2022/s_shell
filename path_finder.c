#include "phics.h"
#include "main.h"
#define MAX_PATH_LENGTH 100
/**
 * _strtok - tokenise command
 * @command: command
 * @arg: tokenised command
 *
 * Return: void
 */
void _path_finder(char *command, char *arg[])
{
int loop = 0;
char *delim = " \n";
char *token = strtok(command, delim);
char *path_holder[300];
int i = 0;
char *path = getenv("PATH");
/*check the access of a file*/

/* if access is 0 the go straight into strtok*/
if (access(command, X_OK) == 0)
{
arg[loop] = strtok(command, delim);
while (arg[loop] != NULL)
{
	loop++;
	arg[loop] = strtok(NULL, delim);
}
arg[loop] = NULL;
}
/*if access is -1 then we add the command behind it afer adding path values*/
else if(access(command, X_OK) == -1)
{
	loop = 0;
	path_holder[loop] = strtok(path, ":");
	while (path_holder[loop] != NULL)
	{
		/**use_strcat**/
		path_holder[loop] = malloc(MAX_PATH_LENGTH);
		_strcat(path_holder[loop], "/");
		_strcat(path_holder[loop], command);
		if (access(path_holder[loop], X_OK) == 0)
		{
			arg[i] = path_holder[loop];
			arg[i + 1] = NULL;
			free(path_holder[loop]);
			return;
		}
		loop++;
		path_holder[loop] = strtok(NULL, ":");
	}
	for (i = 0; i < loop; i++)
	{
	            free(path_holder[i]);
	}
}
}

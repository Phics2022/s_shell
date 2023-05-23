#include "header.h"
#include "shell.h"
/**
  *handle_path - handles path
  *@args - the value
  *
  *Return: void
  */
void handle_path(char *args, char *ag)
{
	char *path = getenv("PATH");
	char *path2 = strdup(path);
	char *token = NULL;
	char *full_path;
	/*char *final;*/
	int total;
	/**check for accessibility**/
	if(access(args, F_OK | X_OK) == 0)
	{
		strcpy(ag, args);
		return;
	}
	/**tokenise path**/
	token = strtok(path2, ":");
	while (token != NULL)
	{
		total  = strlen(token) + strlen(args) + 2;
		full_path = malloc(sizeof(char) * total);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, args);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			strcpy(ag, full_path);
			free(full_path);
			free(path2);
			return;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path2);
	strcpy(ag, args);
	return;
}

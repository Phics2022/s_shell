#include "phics.h"
#define MAX_CHAR 1024
/** Implementing the path using chura's concept**/
/**
  1. get the command from the parameter
  2. check the access 
  3. get the env variable for path
  4. tokenise the variabe
  5. copy the command to the array pointer
  6. add '/' at the end
  7. add 'the command behind'
  8. return nothing
  */
void implement_path2(char *command, char *path[])
{
	/** get the env var of PATH**/
	char *path_holder[MAX_CHAR];
	char *get_path = getenv("PATH");
	char *path_tok = NULL;
	int i = 0;
	/**check the accessibility**/
	if (access(command, X_OK) != -1)
		return;
	/*tokenise that path variable*/
	path_tok = strtok(get_path, ":");
	while(path_tok != NULL)
	{
		/**copy the path_tok into path**/
		path_holder[i] = malloc(strlen(path_tok) + strlen(command) + 2);
		strcpy(path_holder[i], path_tok);
		strcat(path_holder[i], "/");
		strcat(path_holder[i], command); 
		i++;
		path_tok = strtok(NULL, ":");
	}
	path_holder[i] = "\0";
}
int main(void)
{
	char *command = NULL;
	size_t n = 0;
	int i = 0;
	ssize_t get_line = getline(&command, &n, stdin);
	char *path[MAX_CHAR];
	implement_path2(command, path);
	return (0);
}

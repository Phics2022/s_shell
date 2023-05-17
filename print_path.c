#include "phics.h"
extern char **environ;
 int main(void)
{
	int i = 0;
	char *env;
	while(environ[i] != NULL)
	{
		env = environ[i];
		printf("%s\n", env);
		i++;
	}
	return (0);
}

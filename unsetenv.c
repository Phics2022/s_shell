#include "phics.h"
/**
  plan
  find if exists
  loop through environ till reach the value
  move each value a step backward therby deleting the environmant variable
  **/
extern char **environ;
int _unsetenv(const char *name)
{
	char **env = environ;
	if(getenv(name) == NULL)
	{
		printf("%s does not exist\n", name);
		return (0);
	}

	while(*env != NULL)
	{
		if (strncmp(*env, name, strlen(name) == 0))
		{
			char **point = env;
			while(*point != NULL)
			{
				*point = *(point + 1);
				point++;
			}
			printf("successful");
			return (0);
		}
		env++;
	}
	return (-1);
}
int main(void)
{
	_unsetenv("CHURA");
	return (0);
}

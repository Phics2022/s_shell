#include "header.h"
#include "shell.h"
/**
  *_getline - implement the getline function
  *name: name of variable
  *
  *Return: NULL or the loop
  */
char *_getenv(const char *name)
{
	while (*environ != NULL)
	{
		if(strncmp(*environ, name, strlen(name)) == 0)
		{
			return ((environ)[strlen(name + 1)]);
		}
		environ++;
	}
	return (NULL);
}

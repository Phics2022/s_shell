#include "header.h"
#include "shell.h"
/**
  *change a directory
  *@name: directory name
  *
  *Return: int
  */
int cd_dir(char *name)
{
	int cd_checker;
	if (name == NULL)
	{
		chdir(getenv("HOME"));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getenv("HOME"), 1);
		return (0);
	}
	else if (strcmp("-", name) == 0)
	{
		chdir(getenv("OLDPWD"));
		return (0);
	}
	else
	{
		cd_checker = chdir(name);
		if (cd_checker == -1)
		{
			perror("chdir");
			return (0);
		}
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", name, 1);
		return (0);
	}
	return (0);
}

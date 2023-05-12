#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main(int ac, char **av, char **env)
{
	printf("The env address is %p\n", &env);
	printf("The environ address id %p\n", &environ);
}

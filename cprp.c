#include "phics.h"
int main(void)
{
	char *path =  getenv("PATH");
	char *tok = strtok(path, ":");
	int fd;
	int i = 0;
	char *args[4000];
	while(tok != NULL)
	{
		fd = open("path", O_CREAT | O_WRONLY | O_TRUNC);
		write(fd, tok, strlen(tok));
		write(fd, "/ls", 3);
		read(fd, args[i], strlen(tok) + 3);
		close(fd);
		printf("%s\n", args[i]);
		i++;
		tok = strtok(NULL, ":");
	}
	args[i] = NULL;

}

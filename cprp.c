#include "phics.h"
int main(void)
{
	char *path =  getenv("PATH");
	char *tok = strtok(path, ":");
	int fd;
	int i = 0;
	char **args = (char **)malloc(sizeof(char *) *4000);
	while(tok != NULL)
	{
		fd = open("path.txt", O_RDWR);
		write(fd, tok, strlen(tok));
		write(fd, "/ls", 3);
		char reader[1024];
		read(fd, reader,strlen(tok) + 3);
		printf("%s\n", reader);
		//*(args + 1) = reader;
		close(fd);
		//printf("%s\n", *(args + i));
		i++;
		tok = strtok(NULL, ":");
	}
	*(args + i) = NULL;

}

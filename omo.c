#include "phics.h"
int main()
{
	int fd;
	char buff[109];
	fd = open("path.txt", O_RDWR);
	read(fd, buff, 10);
	printf("%s", buff);
	close(fd);
	

}

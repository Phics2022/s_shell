#include "phics.h"

#include "main.h"

ssize_t _getline(__attribute__((unused))char **ptr, __attribute__((unused))size_t *n)
{
	char *buff = malloc(sizeof(char *) * 1024);
	/*read the command prompt*/
	ssize_t read_check = read(STDIN_FILENO, buff, 1024);
	read_check -= 1;
	if (read_check == -1)
	{
		perror("read");
		return (read_check);
	}
	/* equal n to length*/
	/*malloc ptr*/
	if (*ptr == NULL)
	{
		*ptr = malloc(sizeof(char *) * read_check);
	}
	/*copy the buff into the ptr*/
	while(*buff)
	{
		*ptr = buff;
		ptr++;
		buff++;
	}
	return (read_check);
}

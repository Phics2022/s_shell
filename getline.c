#include "header.h"
#include "shell.h"
#define MAX_PATH 256
ssize_t _getline(char **lineptr, __attribute__((unused)) size_t *n, FILE *stream)
{
	/*first of all we read and store it into a buff*/
	char buff[MAX_PATH] = "";
	ssize_t read_count = 0;
	read_count = read(fileno(stream), buff, 256);
	if (read_count == 0 || read_count == -1)
	{
		return (-1);
	}
	*lineptr = malloc(sizeof(char) * MAX_PATH);
	/*copy the buff into lineptr*/
	strcpy(*lineptr, buff);
	return (read_count);
}

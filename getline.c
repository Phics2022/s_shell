#include "phics.h"

#include "main.h"

ssize_t _getline(char **ptr, __attribute__((unused))size_t *n, FILE *stream)
{
	char *buff = malloc(sizeof(char ) * 1024);
	/*read the command prompt*/
	ssize_t read_check = read(fileno(stream), buff, 1024);
	int i;
	if (read_check == 0)
	{
		return (-1);
	}
	/* equal n to length*/
	read_check -= 1;
	/*malloc ptr*/
	*ptr = malloc(sizeof(char ) * read_check);
	/*copy the buff into the ptr*/
	for(i = 0; i < read_check; i++)
	{
		(*ptr)[i] = buff[i];
	}
	(*ptr)[i] = '\0';
	/*return the read byte*/
	free(buff);
	return (read_check);
}

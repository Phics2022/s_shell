#include "phics.h"

#include "main.h"
#define MAX_PATH 300
ssize_t _getline(char **ptr, __attribute__((unused))size_t *n, FILE *stream)
{
	char *buff = malloc(sizeof(char ) * MAX_PATH);
	/*read the command prompt*/
	ssize_t read_check = read(fileno(stream), buff, MAX_PATH);
	int i;
	if (read_check == 0 || read_check == -1)
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

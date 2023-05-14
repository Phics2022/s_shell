#include "main.h"
#include "phics.h"

int main(void)
{
	/*testing the getline function*/
	char *ptr = NULL;
	size_t n = 0;
	ssize_t check = _getline(&ptr, &n, stdin);
	if (check == -1)
	{
		printf("getline failed\n");
	}
	printf("Your command is %sand the length is %ld\n", ptr, check);
	return (0);
}

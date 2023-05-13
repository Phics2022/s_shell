#include "main.h"
#include "phics.h"

int main(void)
{
	/*testing the getline function*/
	char *ptr = NULL;
	size_t n = 0;
	ssize_t check = _getline(&ptr, &n);
	if (check == -1)
	{
		printf("getline failed\n");
	}
	printf("Your command is %sand the length is %zd\n", ptr, check);
	return (0);
}

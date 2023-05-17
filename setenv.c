#include "phics.h"
#include "main.h"
int _setenv( char *name, char *value, int overwrite)
{
	int env_length, total_length;
	char **new_env = NULL;
	char *new_var;
	/*check if val exists and if overwite is allowed*/
	/*by default i made overwrite un available by giving it the value of 0*/
	if(getenv(name) == 0 && overwrite == 0)
		return (0);

	/*if not*/
	/*get the lenght of environ*/
	for (env_length = 0; environ[env_length] != NULL; env_length++);
	/*allocate memory for the new environ*/
	*new_env = malloc(sizeof(char *) * (env_length + 2));
	/*copy environ into new environ*/
	new_env = environ;
	/*copy the name=value into the new var*/
	total_length = strlen(name) + strlen(value) + 2;
	new_var = malloc(sizeof(char) * total_length);
	strcat(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);
	/* copy new var into end of new environ*/
	new_env[env_length] = new_var;
	new_env[env_length + 1] = NULL;
	/* change environ to new env*/
	environ = new_env;
	free(new_env);
	free(new_var);
	return (0);
}

int main(void)
{
	_setenv("PHICS", "SE", 0);
	setenv("CHURA", "se", 0);
	printf("success\n");
	return 0;
}

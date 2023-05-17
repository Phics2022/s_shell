#include "phics.h"
/**
  plan:
  get the value of path
  tokenise it into a char *
  put each tok into a loop to be added to the linked list
  print the linked list&
  
**/
void add_node(path **head, char *value)
{
	path *temp = malloc(sizeof(path));
	temp->var = value;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		return;
	}
	path *temp2 = *head;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;

}
void print_list(path *head)
{
	path *temp = head;
	while(temp != NULL)
	{
		printf("%s\n", temp->var);
		temp = temp->next;
	}
}
int main(void)
{
	path *head = NULL;
	char *path_holder = getenv("PATH");
	char *path_token = strtok(path_holder, ":");
	while(path_token != NULL)
	{
		add_node(&head, path_token);
		path_token = strtok(NULL, ":");
	}
	print_list(head);
	return (0);
}

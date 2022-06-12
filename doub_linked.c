#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head, *temp;

void create_list(void)
{
	int data, choice;
	struct node *newnode;

	printf("To enter data press 1, otherwise 0\n");
	scanf("%d", &choice);
	while (choice != 0)
	{
		printf("Enter data \n");
		scanf("%d", &data);
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = data;
		if (head == 0)
		{
			head = temp = newnode;
			newnode->prev = 0;
		}
		else
		{
			newnode->prev = temp;
			temp->next = newnode;
			temp = newnode;
		}

		printf("To enter data press 1, otherwise 0\n");
		scanf("%d", &choice);
	}
	temp->next = temp->prev;

}

int main()
{
	create_list();
	temp = head;
	/* printf("%d\n", head->data); */
	while(temp != 0)
	{
		temp = temp->next;
	}
	while(temp != 0)
	{
		printf("%d", temp->data);
		temp = temp-> prev;
	}
	return (0);
}

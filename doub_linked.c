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

}

void insert_at_beg()
{
	struct node *new_node;
	int data;

	printf("Enter data: ");
	scanf("%d", &data);

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->prev = 0;
	new_node->data = data;
	new_node->next = head;
	head->prev = new_node;
	head =new_node;
}

int main()
{
	create_list();
	insert_at_beg();
	temp = head;

	while(temp != 0)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	while(temp != 0)
	{
		printf("%d", temp->data);
		temp = temp-> prev;
	}
	return (0);
}

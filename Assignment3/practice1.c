#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
	struct	LinkedList *next;
	int		data;
};

// traverse LinkedList
void	printList(struct LinkedList *head)
{
	struct	LinkedList	*cur;

	cur = head->next;
	while (cur != 0)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void	appendList(struct LinkedList *head, int data)
{
	struct	LinkedList	*cur;
	struct	LinkedList	*new;

	new = malloc(sizeof(struct LinkedList));
	new->data = data;
	cur = head->next;
	while (cur->next != 0)
		cur = cur->next;
	cur->next = new;
}

void	insertList(struct LinkedList *node, int data)
{
	struct LinkedList	*now;
	struct LinkedList	*new;
	struct LinkedList	*tmp;

	new = malloc(sizeof(struct LinkedList));
	now = node;
	tmp = now->next;
	now->next = new;
	new->data = data;
	new->next = tmp;
}

void	removeList(struct LinkedList *node)
{
	struct LinkedList *new;

	new = node->next->next;
	node->next = new;
}

struct	LinkedList	*reverseList(struct LinkedList *head)
{
	struct	LinkedList	*prev;
	struct	LinkedList	*cur;
	struct	LinkedList	*tmp;

	prev = 0;
	cur = head->next;
	while (cur != 0)
	{
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return (prev);
}

int	main()
{
	struct	LinkedList	*head;
	struct	LinkedList	*node1;
	struct	LinkedList	*node2;
	struct	LinkedList	*node3;
	int					i;

	head = malloc(sizeof(struct LinkedList));
	node1 = malloc(sizeof(struct LinkedList));
	node2 = malloc(sizeof(struct LinkedList));
	node3 = malloc(sizeof(struct LinkedList));
	if (head == 0 || node1 == 0 || node2 == 0 || node3 == 0)
		return (0);
	head->next = node1;
	node1->data = 1;
	node1->next = node2;
	node2->data = 2;
	node2->next = node3;
	node3->data = 3;
	printList(head);
	insertList(node1, 4);
	appendList(head, 5);
	printList(head);
	removeList(node3);
	printList(head);
	head->next = reverseList(head);
	printList(head);
	return (0);
}

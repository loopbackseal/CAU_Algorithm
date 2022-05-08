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
		printf("%3d ", cur->data);
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
	struct	LinkedList	*tmp;
	int					i;
	int					num;

	head = malloc(sizeof(struct LinkedList));
	if (head == 0)
		return (0);
	tmp = head;
	i = 0;
	while (i < 10)
	{
		struct	LinkedList	*node;
		node = malloc(sizeof(struct LinkedList));
		if (node == 0)
			return (0);
		node->data = rand() % 99;
		tmp->next = node;
		tmp = node;
		i++;
	}
	printList(head);
	insertList(head->next, -1);
	printList(head);
	appendList(head, -2);
	printList(head);
	removeList(head->next->next->next);
	printList(head);
	head->next = reverseList(head);
	printList(head);
	return (0);
}

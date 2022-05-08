#include <stdio.h>
#include <stdlib.h>

struct	LinkedList {
	struct	LinkedList	*next;
	int		data;
};

void	printList(struct LinkedList *head)
{
	struct	LinkedList	*cur;

	cur = head->next;
	while (cur != 0)
	{
		printf("%3d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int	isIn(int num, int *numList, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (num == numList[i])
		{
			printf("%d is duplicated, delete Node...\n", numList[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	delNode(struct	LinkedList *node)
{
	struct	LinkedList	*tmp;

	if (node->next->next != 0)
	{
		tmp = node->next->next;
		node->next = tmp;
	}
	else
		node->next = 0;
}

int main()
{
	struct	LinkedList	*head;
	struct	LinkedList	*tmp;
	int					i;

	head = malloc(sizeof(struct	LinkedList));
	if (head == 0)
		return (0);
	tmp = head;
	i = 0;
	while (i < 20)
	{
		struct	LinkedList *node;
		node = malloc(sizeof(struct	LinkedList));
		if (node == 0)
			return (0);
		node->data = rand() % 50 + 1;
		tmp->next = node;
		tmp = node;
		i++;
	}
	printList(head);
	struct	LinkedList	*prev;
	int					numList[30];
	int					count;

	count = 0;
	prev = head;
	tmp = head->next;
	while (tmp != 0)
	{
		if (isIn(tmp->data, numList, count) == 1)
			delNode(prev);
		else
		{
			numList[count] = tmp->data;
			count++;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	printList(head);
	return (0);
}


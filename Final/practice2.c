#include <stdio.h>
#include <stdlib.h>

typedef struct vertex
{
	int	color; // 0 -> white 1 -> gray 2 -> black
	int	d; // distance
	int	idx; // index
	int	p; // parents
} V;

typedef	struct	Node
{
	V	v;
	struct	Node	*next;
} Node;

typedef	struct	Queue
{
	Node	*front;
	Node	*rear;
	int		count;
} Queue;

void initQueue(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

void	enqueue(Queue *queue, V v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->v = v;
	newNode->next = NULL;

	if (queue->count == 0)
	{
		queue->front = newNode;
	}
	else
	{
		queue->rear->next = newNode;
	}
	queue->rear = newNode;
	queue->count++;
}

V dequeue(Queue *queue)
{
	V		v;
	Node	*ptr;

	if (queue->count == 0)
	{
		printf("Queue is empty!\n");
		return (v);
	}
	ptr = queue->front;
	v = ptr->v;
	queue->front = ptr->next;
	free(ptr);
	queue->count--;

	return (v);
}

int	main(void)
{
	int		graph[8][8] = {
		{1, 2, -1},
		{0, -1},
		{0, 3, -1},
		{2, 4, 5, -1},
		{3, 5, 6, -1},
		{3, 4, 6, 7, -1},
		{4, 5, 7, -1},
		{5, 6, -1}
	};
	V	r,v,s,w,t,x,u,y;
	V	vertex[8] = {r, v, s, w, t, x, u, y};
	Queue	q;
	initQueue(&q);
	// implement BFS
	int	i = 0;
	while (i < 8)
	{
		V tmp = vertex[i];
		tmp.color = 0;
		tmp.d = -1;
		tmp.p = -1;
		tmp.idx = i;
		i++;
	}
	s.color = 1;
	s.d = 0;
	enqueue(&q, s);
	while (q.count != 0)
	{
		V tmp = dequeue(&q);
		int	i = 0;
		while (graph[tmp.idx][i] != -1)
		{
			int idx = graph[tmp.idx][i];
			if (vertex[idx].color == 0)
			{
				vertex[idx].color = 1;
				vertex[idx].d = tmp.d + 1;
				vertex[idx].p = tmp.idx;
				enqueue(&q, vertex[idx]);
			}
			i++;
		}
		tmp.color = 2;
	}
	return (0);
}

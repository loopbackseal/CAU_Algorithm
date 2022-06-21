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
	int				v;
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

void	enqueue(Queue *queue, int v)
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

int dequeue(Queue *queue)
{
	int		v;
	Node	*ptr;

	if (queue->count == 0)
	{
		printf("Queue is empty!\n");
		return (-1);
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
	V		r,v,s,w,t,x,u,y;
	r.idx = 0;
	r.color = 0;
	r.d = -1;
	v.idx = 1;
	v.color = 0;
	v.d = -1;
	s.idx = 2;
	w.idx = 3;
	w.color = 0;
	w.d = -1;
	t.idx = 4;
	t.color = 0;
	t.d = -1;
	x.idx = 5;
	x.color = 0;
	x.d = -1;
	u.idx = 6;
	u.color = 0;
	u.d = -1;
	y.idx = 7;
	y.color = 0;
	y.d = -1;
	V		vertex[8] = {r, v, s, w, t, x, u, y};
	char	name[8] = {'r', 'v', 's', 'w', 't', 'x', 'u', 'y'};
	Queue	q;
	initQueue(&q);
	// implement BFS
	s.color = 1;
	s.d = 0;
	enqueue(&q, 2);
	while (q.count != 0)
	{
		int tmp = dequeue(&q);
		int	i = 0;
		while (graph[tmp][i] != -1)
		{
			int idx = graph[tmp][i];
			if (vertex[idx].color == 0)
			{
				vertex[idx].color = 1;
				vertex[idx].d = vertex[tmp].d + 1;
				vertex[idx].p = tmp;
				enqueue(&q, idx);
			}
			i++;
		}
		vertex[tmp].color = 2;
	}
	int	i = 0;
	while (i < 8)
	{
		V tmp = vertex[i];
		printf("%c\n", name[i]);
		//printf("%c :\n", name[i]);
		printf("distance: %d, parent: %c\n", tmp.d - vertex[2].d, name[tmp.p]);
		i++;
	}
	return (0);
}

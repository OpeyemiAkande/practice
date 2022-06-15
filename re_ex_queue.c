#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int *array;
};

struct Queue *create_queue(unsigned capacity)
{
	struct Queue* queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->capacity = capacity;

	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int *)malloc(queue->capacity * sizeof(struct Queue));
	return (queue);
}

int is_full(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

int is_empty(struct Queue* queue)
{
	return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
	if (is_full(queue))
		return;
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size += 1;
	printf("%d enqueued to the queue\n", item);
}

int dequeue(struct Queue *queue)
{
	if (is_empty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size -= 1;
	return (item);
}

int front(struct Queue *queue)
{
	if (is_empty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	return (item);
}

int rear(struct Queue *queue)
{
	if (is_empty(queue))
		return INT_MIN;
	int item = queue->array[queue->rear];
	return (item);
}

int main()
{
	struct Queue *queue = create_queue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	printf("%d dequeued from queue\n",dequeue(queue));
	printf("%d is the front element in queue\n", front(queue));
	printf("%d is the rear element in queue\n", rear(queue));
	return (0);
}

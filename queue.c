// Sean Szumlanski
// COP 3502, Fall 2016

// queue.c
// =======
// Linked list-based implementation of queues. Comments are sparse because we
// covered this in class.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedLists.h"  // Functional prototypes & struct definitions for linked lists
#include "queue.h"        // Functional prototypes & struct definitions for queues

int isEmpty(Queue *q)
{
	if (q == NULL || q->list == NULL)
		return 1;

	return (q->list->head == NULL);
}

// When using linked lists, we might (naively?) assume there is always room for more.
int isFull(Queue *q)
{
	return 0;
}

// Insert element at back of queue (using tail insertion).
void enqueue(Queue *q, int data)
{
	tailInsert(q->list, data);
	q->count++;
}

// Remove front of queue (using head removal)
int dequeue(Queue *q)
{
	if (isEmpty(q))
		return EMPTY_QUEUE_ERR;

	q->count--;
	return offWithItsHead(q->list);
}

// Peek at the front of the queue without dequeueing
int peek(Queue *q)
{
	if (isEmpty(q))
		return EMPTY_QUEUE_ERR;

	return q->list->head->data;
}

// Create the queue. Initialize it's internal linked list.
Queue *createQueue(void)
{
	Queue *q = calloc(1, sizeof(Queue));
	q->list = createList();

	return q;
}

// Just a trivial test of the queue's functionality.
int main(void)
{
	// create new queue
	Queue *q = createQueue();

	// enqueue a few elements
	enqueue(q, 44);
	enqueue(q, 45);

	// empty out the queue
	while (!isEmpty(q))
		printf("%d\n", dequeue(q));

	// Exercise: Write this function yourself.
	//destroyQueue(q);

	return 0;
}

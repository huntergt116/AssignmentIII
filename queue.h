// Sean Szumlanski
// COP 3502, Fall 2016

// queue.h
// =======
// Header file for linked list-based implementation of queues. Includes
// struct definitions and functional prototypes.


#ifndef __QUEUE_H  // This is an include guard. It's fantastic!
#define __QUEUE_H


#define EMPTY_QUEUE_ERR INT_MIN;

typedef struct Queue
{
	LinkedList *list;
	int count;
} Queue;


// Functional prototypes.

int isEmpty(Queue *q);

int isFull(Queue *q);

void enqueue(Queue *q, int data);

int dequeue(Queue *q);

int peek(Queue *q);

Queue *createQueue(void);


#endif

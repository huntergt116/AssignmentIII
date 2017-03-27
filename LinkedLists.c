// Sean Szumlanski
// COP 3502, Fall 2016

// LinkedLists.c
// =============
// Linked lists. Supports head removal and tail insertion. Maintains head and
// tail pointers within a LinkedList struct. Comments are sparse because we
// covered this in class.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedLists.h"


node *createNode(int data)
{
	node *n;

	if ((n = malloc(sizeof(node))) == NULL)
		return NULL;

	n->data = data;
	n->next = NULL;

	return n;
}

LinkedList *createList(void)
{
	LinkedList *ptr = calloc(1, sizeof(LinkedList));
	return ptr;
}

node *recursiveDestroyList(node *head)
{
	if (head == NULL)
		return NULL;

	recursiveDestroyList(head->next);
	free(head);

	return NULL;
}

LinkedList *destroyLinkedList(LinkedList *list)
{
	if (list == NULL)
		return NULL;

	recursiveDestroyList(list->head);
	free(list);

	return NULL;
}

void tailInsert(LinkedList *list, int data)
{
	if (list == NULL)
	{
		return;
	}
	if (list->tail == NULL)
	{
		list->head = list->tail = createNode(data);
	}
	else
	{
		list->tail->next = createNode(data);
		list->tail = list->tail->next;
	}
}

void obliterateNode(node *ptr)
{
	free(ptr);
}

int offWithItsHead(LinkedList *list)
{
	int retval;
	node *temp;

	if (list == NULL || list->head == NULL)
		return EMPTY_LIST_ERR;

	retval = list->head->data;

	temp = list->head;
	list->head = list->head->next;
	obliterateNode(temp);

	return retval;
}

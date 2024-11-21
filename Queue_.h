#ifndef Queue_
#define Queue_

#include "Linked_List.h"

typedef struct{
	LinkedList* list;
	int size;
} Queue;

Queue* initQueue(void);

void qPoll(Queue*);

void* qPeek(Queue*);

void qOffer(Queue*, void*, size_t);

void qDelete(Queue*);

int qIsEmpty(Queue*);

#endif
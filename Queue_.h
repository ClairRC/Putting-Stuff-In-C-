#ifndef Queue_
#define Queue_

#include "Linked_List.h"

typedef struct{
	LinkedList* list;
	int size;
} Queue;

Queue* initQueue(void);

void poll(Queue*);

void* peekQueue(Queue*);

void offer(Queue*, void*, size_t);

void deleteQueue(Queue*);

int queueIsEmpty(Queue*);

#endif
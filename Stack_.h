#ifndef Stack_
#define Stack_

#include "Array_List.h"

/*
* I'd probably find this better to implement as a linked list with
* how I've done this, because linked list is more flexible with the size
* of each new element added, whereas my arraylist needs the same size
* for each element defined at the start. However, a stack using my linked list
* implementation would be super trivial and basically just the same as my queue implementation so.
* For the sake of learning and variety I'm doing it this way.
*/

typedef struct {
	ArrayList* list;
	int size;
} Stack;

Stack* initStack(size_t size);

void push(Stack*, void*);

void pop(Stack*);

void* peekStack(Stack*);

void deleteStack(Stack*);

int stackIsEmpty(Stack*);

#endif

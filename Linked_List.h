#ifndef Linked_List
#define Linked_List

#include<stddef.h>;

typedef struct {
	void* data;
	struct Node* nextNode;
	struct Node* prevNode;
} Node;

typedef struct {
	struct Node* head;
	struct Node* tail;
	int size;
} LinkedList;

LinkedList* initLinkedList();

Node* llCreateNode(void*, size_t);

void llInsertAtHead(LinkedList*, void*, size_t);

void llInsertAtTail(LinkedList*, void*, size_t);

void llRemoveAtHead(LinkedList*);

void llRemoveAtTail(LinkedList*);

void* llGetAtIndex(LinkedList*, int);

void llRemoveAllNodes(LinkedList*);

void llDelete(LinkedList*);

int llIsEmpty(LinkedList*);

#endif
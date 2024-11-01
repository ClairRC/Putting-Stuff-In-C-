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

Node* createNode(void*);

void insertAtHead(LinkedList*, void*, size_t);

void insertAtTail(LinkedList*, void*, size_t);

void removeAtHead(LinkedList*);

void removeAtTail(LinkedList*);

void* getAtIndex(LinkedList*, int);

void removeAllNodes(LinkedList*);

void deleteLinkedList(LinkedList*);

int linkedListisEmpty(LinkedList*);

#endif
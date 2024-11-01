#include "Linked_List.h"
#include <stdlib.h>
#include <string.h>

//Creates new linked list onto the heap
LinkedList* initLinkedList() {
	LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));

	//Returns if allocation fails
	if (newList == NULL) {
		return NULL;
	}

	//Initialize values
	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;

	return newList;
}

//Create new Node
Node* createNode(void* data, size_t size) {
	Node* newNode = (Node*) malloc(sizeof(Node));

	//Return if allocation fails
	if (newNode == NULL)
		return NULL;

	//Initialize Values
	newNode->data = malloc(size);
	newNode->nextNode = NULL;
	newNode->prevNode = NULL;

	if (newNode->data == NULL) {
		free(newNode);
		return;
	}

	//Copy memory to node
	memcpy(newNode->data, data, size);

	return newNode;
}

//Insert at head
void insertAtHead(LinkedList* list, void* data, size_t size) {
	if (list == NULL)
		return;

	Node* newNode = createNode(data, size);

	//Return if memory allocation fails
	if (newNode == NULL)
		return;

	//Pointer to current head node
	Node* currHead = list->head;

	//New node's next is the head node, prev is NULL
	newNode->nextNode = currHead;
	newNode->prevNode = NULL;

	//If head node exists, changes it's next node to new node
	if(currHead != NULL)
		currHead->prevNode = newNode;

	//If list is empty, new entry is both head and tail node
	if (list->head == NULL && list->tail == NULL)
		list->tail = newNode;

	list->head = newNode;
	++list->size;
}

//Insert at tail
void insertAtTail(LinkedList* list, void* data, size_t size) {
	if (list == NULL)
		return;

	Node* newNode = createNode(data, size);

	//Return if allocation failse
	if (newNode == NULL)
		return;

	//Current tail reference
	Node* currTail = list->tail;

	//New node's previous is tail, next is NULL
	newNode->nextNode = NULL;
	newNode->prevNode = currTail;

	//If tail exists, changes it's next node to be this one
	if (currTail != NULL)
		currTail->nextNode = newNode;

	//If list is empty, new entry is both head and tail node
	if (list->head == NULL && list->tail == NULL)
		list->head = newNode;

	list->tail = newNode;
	++list->size;
}

//Remove at head
void removeAtHead(LinkedList* list) {
	if (list == NULL || list->head == NULL)
		return;

	//If only 1 item in list, call removeAllNodes
	if (list->head == list->tail) {
		removeAllNodes(list);
		return;
	}

	Node* currHead = list->head;

	//Reference to new head node
	Node* newHead = currHead->nextNode;

	newHead->prevNode = NULL;

	//Set head node reference
	list->head = newHead;
	--list->size;

	//Deallocate memory
	free(currHead->data);
	free(currHead);
}

//Remove at tail
void removeAtTail(LinkedList* list) {
	if (list == NULL || list->tail == NULL)
		return;

	//If only 1 item in list, call removeAllNodes
	if (list->head == list->tail) {
		removeAllNodes(list);
		return;
	}

	Node* currTail = list->tail;

	//Reference to new tail node
	Node* newTail = currTail->prevNode;

	newTail->nextNode = NULL;

	//Set tail node reference
	list->tail = newTail;
	--list->size;

	//Deallocate memory
	free(currTail->data);
	free(currTail);
}

//Remove all nodes
void removeAllNodes(LinkedList* list) {
	if (list == NULL || (list->head == NULL && list->tail == NULL))
		return;

	//Current head
	Node* nc = list->head;

	//While there is more stuff in the list
	while (nc != NULL) {
		//Free node, move on to next
		Node* temp = nc;
		nc = temp->nextNode;

		free(temp->data);
		free(temp);
	}

	//Set tail and head references to NULL
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

//Return data at index
void* getAtIndex(LinkedList* list, int index) {
	if (list == NULL || index >= list->size || index < 0)
		return NULL;

	Node* nc = list->head;

	//Traverses list until index
	for (int i = 0; i < index; ++i) {
		nc = nc->nextNode;
	}

	return nc->data;
}

//Delete all nodes and list from the heap
void deleteLinkedList(LinkedList* list) {
	if (list == NULL)
		return;

	removeAllNodes(list);
	free(list);
}

int linkedListIsEmpty(LinkedList* list) {
	return list->size == 0;
}
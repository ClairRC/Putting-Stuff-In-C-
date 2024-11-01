#include <stdlib.h>
#include "Linked_List.h"
#include "Queue_.h"

Queue* initQueue() {
	Queue* q = malloc(sizeof(Queue));

	if (q == NULL)
		return NULL;

	q->list = initLinkedList();

	if (q->list == NULL)
		return NULL;

	q->size = 0;

	return q;
}

void poll(Queue* q) {
	if (q == NULL)
		return;

	LinkedList* list = q->list;

	removeAtTail(list);
	
	--q->size;
}

void* peekQueue(Queue* q) {
	if (q == NULL || q->list == NULL || q->list->tail == NULL)
		return NULL;

	LinkedList* list = q->list;
	Node* listTail = list->tail;

	return listTail->data;
}

void offer(Queue* q, void* data, size_t size) {
	if (q == NULL)
		return;

	LinkedList* list = q->list;
	insertAtHead(list, data, size);

	++q->size;
}

void deleteQueue(Queue* q) {
	if (q == NULL)
		return;

	LinkedList* list = q->list;

	deleteLinkedList(list);

	free(q);
}

int queueIsEmpty(Queue* q) {
	return q->size == 0;
}
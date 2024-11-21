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

void qPoll(Queue* q) {
	if (q == NULL)
		return;

	LinkedList* list = q->list;

	llRemoveAtTail(list);
	
	--q->size;
}

void* qPeek(Queue* q) {
	if (q == NULL || q->list == NULL || q->list->tail == NULL)
		return NULL;

	LinkedList* list = q->list;
	Node* listTail = list->tail;

	return listTail->data;
}

void qOffer(Queue* q, void* data, size_t size) {
	if (q == NULL)
		return;

	LinkedList* list = q->list;
	llInsertAtHead(list, data, size);

	++q->size;
}

void qDelete(Queue* q) {
	if (q == NULL)
		return;

	LinkedList* list = q->list;

	llDelete(list);

	free(q);
}

int qIsEmpty(Queue* q) {
	return q->size == 0;
}
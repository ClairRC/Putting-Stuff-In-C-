#include <stdlib.h>
#include <stdio.h>
#include "Array_List.h"
#include "Stack_.h"

Stack* initStack(size_t size) {
	Stack* stack = malloc(sizeof(Stack));
	
	if (stack == NULL)
		return NULL;

	ArrayList* list = initArrayList(size);

	if (list == NULL) {
		free(stack);
		return NULL;
	}

	stack->size = 0;
	stack->list = list;

	return stack;
}

void stPush(Stack* stack, void* data) {
	if (stack == NULL)
		return;

	alAdd(stack->list, data);
	++stack->size;
}

void stPop(Stack* stack) {
	if (stack == NULL || stack->list == NULL)
		return;

	alRemoveAtIndex(stack->list, stack->list->size-1);
	--stack->size;
}

void* stPeek(Stack* stack) {
	if (stack == NULL || stack->list == NULL)
		return NULL;

	return alGetFromIndex(stack->list, stack->list->size - 1);
}

void stDelete(Stack* stack) {
	if (stack == NULL)
		return;

	if (stack->list == NULL) {
		free(stack);
		return;
	}

	alDelete(stack->list);
	free(stack);
}

int stIsEmpty(Stack* stack) {
	return stack->size == 0;
}
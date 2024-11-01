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

void push(Stack* stack, void* data) {
	if (stack == NULL)
		return;

	add(stack->list, data);
	++stack->size;
}

void pop(Stack* stack) {
	if (stack == NULL || stack->list == NULL)
		return;

	removeAtIndex(stack->list, stack->list->size-1);
	--stack->size;
}

void* peekStack(Stack* stack) {
	if (stack == NULL || stack->list == NULL)
		return NULL;

	return get(stack->list, stack->list->size - 1);
}

void deleteStack(Stack* stack) {
	if (stack == NULL)
		return;

	if (stack->list == NULL) {
		free(stack);
		return;
	}

	deleteArrayList(stack->list);
	free(stack);
}

int stackIsEmpty(Stack* stack) {
	return stack->size == 0;
}
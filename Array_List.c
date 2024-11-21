#include <stdlib.h>
#include <string.h>
#include "Array_List.h"

ArrayList* initArrayList(size_t dataTypeSize) {
	ArrayList* list = malloc(sizeof(ArrayList));

	if (list == NULL)
		return NULL;

	list->arr = malloc(ArrayListStartSize * dataTypeSize);

	if (list->arr == NULL) {
		free(list);
		return NULL;
	}

	list->elementSize = dataTypeSize;
	list->currMaxSize = ArrayListStartSize;
	list->size = 0;

	return list;
}

void alAdd(ArrayList* list, void* data) {
	if (list == NULL)
		return;

	if (list->size >= list->currMaxSize)
		alResize(list);

	void* destAddress = (char*)list->arr + list->size * list->elementSize;
	memcpy(destAddress, data, list->elementSize);

	++list->size;
}

void alAddAtIndex(ArrayList* list, void* data, int index) {
	if (index < 0)
		index = 0;

	if (list == NULL || index >= list->size)
		return;

	if (list->size >= list->currMaxSize)
		alResize(list);

	int lSize = list->size;
	for (int i = lSize - 1; i >= index; --i) {
		void* srcAddress = (char*)list->arr + i * list->elementSize;
		void* destAddress = (char*)srcAddress + list->elementSize;

		memcpy(destAddress, srcAddress, list->elementSize);
	}

	memcpy((char*)list->arr + index * list->elementSize, data, list->elementSize);

	++list->size;
}

void alRemoveAtIndex(ArrayList* list, int index) {
	if (index < 0)
		index = 0;

	if (list == NULL || index >= list->size)
		return;

	int lSize = list->size;
	for (int i = index + 1; i < lSize; ++i) {
		void* srcAddress = (char*)list->arr + i * list->elementSize;
		void* destAddress = (char*)srcAddress - list->elementSize;

		memcpy(destAddress, srcAddress, list->elementSize);
	}

	--list->size;
}

void alSetAtIndex(ArrayList* list, void* data, int index) {
	if (index < 0)
		index = 0;

	if (list == NULL || index >= list->size)
		return;

	void* destAddress = (char*)list->arr + index * list->elementSize;

	memcpy(destAddress, data, list->elementSize);
}

void* alGetFromIndex(ArrayList* list, int index) {
	if (index < 0)
		index = 0;

	if (list == NULL || index >= list->size)
		return NULL;

	void* dataToReturn = (char*)list->arr + index * list->elementSize;

	return dataToReturn;
}

void alClear(ArrayList* list) {
	if (list == NULL)
		return;

	size_t eSize = list->elementSize;

	free(list->arr);

	void* newArr = malloc(ArrayListStartSize * eSize);

	if (newArr == NULL)
		return;

	list->arr = newArr;
	list->currMaxSize = ArrayListStartSize;
	list->size = 0;
}

void alResize(ArrayList* list) {
	if (list == NULL)
		return;

	void* newArr = malloc(2*list->currMaxSize * list->elementSize);

	if (newArr == NULL)
		return;

	for (int i = 0; i < list->size; ++i) {
		void* destAddress = (char*)newArr + i * list->elementSize;
		void* srcAddress = (char*)list->arr + i * list->elementSize;
		memcpy(destAddress, srcAddress, list->elementSize);
	}

	free(list->arr);

	list->arr = newArr;
	list->currMaxSize *= 2;
}

void alDelete(ArrayList* list) {
	if (list == NULL)
		return;

	free(list->arr);
	free(list);
}

int alIsEmpty(ArrayList* list) {
	return list->size == 0;
}
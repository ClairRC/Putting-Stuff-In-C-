#ifndef Hash_Map
#define Hash_Map

#define HashMapStartSize 16
#define HashMapMaxCapacity 0.7

#include "Array_List.h"
#include <stddef.h>

typedef struct {
	void* arr;
	int currMaxSize;
	float maxCapacity;
	int size;
} HashMap;

typedef struct {
	void* value;
	char* key;
} HashMapNode;

HashMap* initHashMap();

unsigned long hash(char* str);

void put(HashMap*, char*, void*, size_t);

void* getValue(HashMap*, char*);

void* getKey(HashMap*, void*);

int hashMapIsEmpty(HashMap*);

HashMapNode* createHashMapNode(char*, void*, size_t);

#endif
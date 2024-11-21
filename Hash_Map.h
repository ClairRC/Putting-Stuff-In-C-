#ifndef Hash_Map
#define Hash_Map

#define HashMapStartSize 16
#define HashMapThreshold 0.7

#include <stddef.h>

typedef struct {
	struct HashMapNode* nextNode;
	void* value;
	char* key;
} HashMapNode;

typedef struct {
	struct HashMapNode** arr;
	int currMaxSize;
	int maxCapacity;
	int size;
} HashMap;

HashMap* initHashMap();

unsigned long hash(char* str);

void put(HashMap*, char*, void*, size_t);

void* getValue(HashMap*, char*);

//int hashMapIsEmpty(HashMap*);

void addHashMapNode(HashMap*, HashMapNode*, int);

HashMapNode* createHashMapNode(char*, void*, size_t);

#endif
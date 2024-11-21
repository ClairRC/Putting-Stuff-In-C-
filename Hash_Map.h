#ifndef Hash_Map
#define Hash_Map

#define HashMapStartSize 16
#define HashMapThreshold 0.7

#include <stddef.h>

typedef struct {
	struct HashMapNode* nextNode;
	size_t size;
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

void hmPut(HashMap*, char*, void*, size_t);

void hmRemoveValue(HashMap*, char*);

void* hmGetValueFromKey(HashMap*, char*);

HashMapNode* hmAddNode(HashMap*, HashMapNode*, int);

void hmRemoveNode(HashMap*, HashMapNode*);

HashMapNode* hmCreateNode(char*, void*, size_t);

void hmResize(HashMap*);

int hmIsEmpty(HashMap*);

void hmDelete(HashMap**);
#endif
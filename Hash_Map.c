#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Hash_Map.h"
#include "Linked_List.h"

HashMap* initHashMap() {
	HashMap* map = malloc(sizeof(HashMap));

	if (map == NULL)
		return NULL;

	map->arr = calloc(HashMapStartSize, sizeof(LinkedList*));

	if (map->arr == NULL) {
		free(map);
		return NULL;
	}

	map->currMaxSize = HashMapStartSize;
	map->size = 0;
	map->maxCapacity = HashMapMaxCapacity;

	return map;
}

//djb2 hash function
unsigned long hash(char* str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash;
}

void put(HashMap* map, char* key, void* value, size_t size) {

}

void* getValue(HashMap* map, char* key) {

}

HashMapNode* createHashMapNode(char* key, void* value, size_t size) {
	HashMapNode* newNode = malloc(sizeof(HashMapNode));

	if (newNode == NULL)
		return NULL;
	
	int keySize = 0;
	while (key[keySize++] != NULL);

	newNode->key = malloc(keySize * sizeof(char));
	
	if (newNode->key == NULL) {
		free(newNode);
		return NULL;
	}

	newNode->value = malloc(size);

	if (newNode->value == NULL) {
		free(newNode->key);
		free(newNode);
		return NULL;
	}

	memcpy(newNode->key, key, keySize * sizeof(char));
	memcpy(newNode->value, value, size);

	return newNode;
}
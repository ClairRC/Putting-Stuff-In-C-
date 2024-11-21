#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Hash_Map.h"

//Create hashmap and return pointer
HashMap* initHashMap() {
	HashMap* map = (HashMap*) malloc(sizeof(HashMap));

	//Return if malloc fails
	if (map == NULL)
		return NULL;

	map->currMaxSize = HashMapStartSize;
	map->maxCapacity = map->currMaxSize * HashMapThreshold;
	map->size = 0;

	//Array has 16 buckets, each holding a pointer to a node.
	map->arr = (HashMapNode**) calloc(map->currMaxSize, sizeof(HashMapNode*)); //Initializes pointers to NULL

	//If calloc fails, return null
	if (map->arr == NULL)
		return NULL;

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

//Put value into hashmap. Must specify size !
void put(HashMap* map, char* key, void* value, size_t size) {
	//Gets bucket index using hash function and key
	int index = hash(key) % map->currMaxSize;

	addHashMapNode(map, createHashMapNode(key, value, size), index);
}

//Gets value with given key
void* getValue(HashMap* map, char* key) {
	//Gets bucket index using hash function and key
	int index = hash(key) % map->currMaxSize;

	HashMapNode* nodeToCheck = map->arr[index];

	//While node is not NULL and keys are not equal, check next node
	while (nodeToCheck != NULL && strcmp(nodeToCheck->key, key) != 0)
		nodeToCheck = nodeToCheck->nextNode;

	//If key is not found, return NULL, else return pointer to value.
	void* valuePtr = nodeToCheck == NULL ? NULL : nodeToCheck->value;

	return valuePtr;
}

//Adds new node
//Index is index of the bucket we're adding too
void addHashMapNode(HashMap* map, HashMapNode* node, int index) {
	//Return if map is null
	if (map == NULL)
		return;

	HashMapNode** insertionPtr = &(map->arr[index]);

	//Find first node that does not have a successor
	while (*insertionPtr != NULL)
		insertionPtr = (&(*insertionPtr)->nextNode);

	*insertionPtr = node;
}

//Creates HashMap node.
//This carries the value and the key
HashMapNode* createHashMapNode(char* key, void* value, size_t size) {
	//Create node
	HashMapNode* node = (HashMapNode*) malloc(sizeof(HashMapNode));
	
	//Return if node can't be allocated
	if (node == NULL)
		return NULL;

	//This gets the size of the key
	int keySize = 0;
	while (key[keySize++] != '\0');
	--keySize;

	node->key = (char*)malloc(keySize*sizeof(char));
	node->value = malloc(size);

	if (node->key == NULL)
		return NULL;

	if (node->value == NULL)
		return NULL;

	strcpy(node->key, key);
	memcpy(node->value, value, size);
	node->nextNode = NULL;

	return node;
}


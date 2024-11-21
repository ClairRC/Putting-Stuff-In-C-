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

	//If calloc fails, return null and remove hashmap
	if (map->arr == NULL) {
		free(map);
		return NULL;
	}

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
void hmPut(HashMap* map, char* key, void* value, size_t size) {
	//Check to make sure key and value aren't null
	if (key == NULL || value == NULL)
		return;

	//Gets bucket index using hash function and key
	int index = abs(hash(key)) % map->currMaxSize;

	HashMapNode* newNode = hmCreateNode(key, value, size);

	//If this is an insertion and not a replacement, increase size
	if (newNode == hmAddNode(map, newNode, index))
		++map->size;

	if (map->size > map->maxCapacity)
		hmResize(map);
}

//Removes node from hash map
void hmRemoveValue(HashMap* map, char* key) {
	//Return if hash map or key are NULL
	if (map == NULL || key == NULL)
		return;

	//Get bucket index
	int index = abs(hash(key)) % map->currMaxSize;

	//If map is empty, return
	if (map->arr[index] == NULL)
		return;

	//Node references
	HashMapNode** prevNode = &(map->arr[index]); //Initialized to first node
	HashMapNode** currNode = &((*prevNode)->nextNode);

	//If node to remove is first node:
	if (strcmp((*prevNode)->key, key) == 0) {
		//Checks if this is the only node. If not, I have to make sure to not break the link
		if ((*currNode) != NULL) {
			map->arr[index] = *currNode;
		}

		free((*prevNode)->key);
		free((*prevNode)->value);
		free(*prevNode);

		//Set this reference in the map to NULL
		map->arr[index] = NULL;
		--map->size;

		return;
	}

	//If the matching node is NOT the first node
	while ((*currNode) != NULL && strcmp((*currNode)->key, key) != 0) {
		prevNode = currNode;
		currNode = &((*currNode)->nextNode);
	}

	//If node is NULL, key isn't in the hash map, just return
	if (*currNode == NULL)
		return;

	//Otherwise, we have the node we need to delete
	HashMapNode** nextNode = &((*currNode)->nextNode); //Node after deletion node so we can link them back up. Could be NULL.

	(*prevNode)->nextNode = *nextNode;

	//FINALLY deletes the node
	free((*currNode)->value);
	free((*currNode)->key);
	free(*currNode);
}

//Gets value with given key
void* hmGetValueFromKey(HashMap* map, char* key) {
	//Gets bucket index using hash function and key
	int index = abs(hash(key)) % map->currMaxSize;

	HashMapNode* nodeToCheck = map->arr[index];

	//While node is not NULL and keys are not equal, check next node
	while (nodeToCheck != NULL && strcmp(nodeToCheck->key, key) != 0)
		nodeToCheck = nodeToCheck->nextNode;

	//If key is not found, return NULL, else return pointer to value.
	void* valuePtr = nodeToCheck == NULL ? NULL : nodeToCheck->value;

	return valuePtr;
}

//Adds new node or updates node
//Index is index of the bucket we're adding to
//This returns a reference to the node so that you can change what you do based on the return value
//Or if you need a reference to it (See the resize function xd)
HashMapNode* hmAddNode(HashMap* map, HashMapNode* node, int index) {
	//Return if map, node, or map's array is null
	if (map == NULL || node == NULL || map->arr == NULL)
		return NULL;

	HashMapNode** insertionPtr = &(map->arr[index]);

	//Find first node that does not have a successor or matching key
	while (*insertionPtr != NULL) {
		//If keys are the same, just replace the value and we don't need to insert anything
		//I think that because we know both nodes aren't null, this isn't a problem
		if (strcmp((*insertionPtr)->key, node->key) == 0) {
			//Only copy data over if the nodes aren't the same. If they are, then we're already doen
			if (*insertionPtr != node) {

				free((*insertionPtr)->value); //Frees current value
				(*insertionPtr)->size = node->size; //Update data size
				(*insertionPtr)->value = malloc((*insertionPtr)->size); //allocates new memory
				memcpy((*insertionPtr)->value, node->value, (*insertionPtr)->size);

				//Free node since we just copy the data.
				free(node);

				return (*insertionPtr); //Return the reference to the node so "node" doesn't become dangling if we still need it
			}

			else
				return (*insertionPtr);
		}

		insertionPtr = (&(*insertionPtr)->nextNode);
	}	

	*insertionPtr = node;
	return *insertionPtr;
}

//Creates HashMap node.
//This carries the value and the key
HashMapNode* hmCreateNode(char* key, void* value, size_t size) {
	//Return if key or value are null
	if (key == NULL || value == NULL)
		return NULL;

	//Create node
	HashMapNode* node = (HashMapNode*) malloc(sizeof(HashMapNode));

	if (node == NULL)
		return NULL;

	//This gets the size of the key for memory allocation
	int keySize = 0;
	while (key[keySize++] != '\0');
//	--keySize;

	node->key = (char*)malloc(keySize*sizeof(char));
	node->value = malloc(size);

	if (node->key == NULL) {
		free(node->value); //Im not sure if this is necessary but I don't wanna chance it.
		free(node);
		return NULL;
	}

	if (node->value == NULL) {
		free(node->key);
		free(node);
		return NULL;
	}

	node->size = size;
	strcpy_s(node->key, keySize, key);
	memcpy(node->value, value, size);
	node->nextNode = NULL;

	return node;
}

//Function for resizing hash map when it gets past the threshold defined in Hash_Map.h
void hmResize(HashMap* map) {
    // Return if map is null
    if (map == NULL)
        return;

    // Update size and capacity
    map->currMaxSize *= 2;
    map->maxCapacity = map->currMaxSize * HashMapThreshold;

    // Allocate new array with increased size
    HashMapNode** oldArr = map->arr; // Reference to the old array
    HashMapNode** newArr = (HashMapNode**)calloc(map->currMaxSize, sizeof(HashMapNode*));

    // Link new array
    map->arr = newArr;

    // For each index in the old array
    for (int i = 0; i < map->currMaxSize / 2; ++i) {
        HashMapNode** nodeToCopy = &(oldArr[i]);

        // If bucket is empty, skip it
        if (*nodeToCopy == NULL)
            continue;

        // Traverse the list and copy nodes
        while (*nodeToCopy != NULL) {
            int newIndex = abs(hash((*nodeToCopy)->key)) % map->currMaxSize;

            // Ensure new node's nextNode is correctly initialized to NULL before adding to new array
            HashMapNode* newNode = *nodeToCopy; // Store the reference to the current node
            *nodeToCopy = (*nodeToCopy)->nextNode; // Move to the next node in the chain
            newNode->nextNode = NULL; // Set nextNode to NULL before adding it to the new array

            // Add the node to the new array at the correct index
            newArr[newIndex] = hmAddNode(map, newNode, newIndex);
        }
    }

    // Free the old array
    free(oldArr);
}

//Simply returns true if hashmap is empty, false if not
int hmIsEmpty(HashMap* map) {
	return map->size == 0;
}

//Deletes hash map
//I need the double pointer becasue I'm editing the pointer, not just the elements of the map
void hmDelete(HashMap** map) {
	//If map is already null then yippee we're done.
	if ((*map) == NULL)
		return;

	//If map's array is already NULL, we just free the map
	if ((*map)->arr == NULL) {
		free((*map));
		*map = NULL;
		return;
	}

	//For each index...
	for (int i = 0; i < (*map)->currMaxSize; ++i) {
		//if bucket is empty, no need to do anything here
		if ((*map)->arr[i] == NULL)
			continue;

		HashMapNode* nodeToCheck = (*map)->arr[i];
		HashMapNode* nextNodeToCheck = nodeToCheck->nextNode;

		//If there is only one node in the bucket
		if (nextNodeToCheck == NULL) {
			free(nodeToCheck);
			continue;
		}

		//If there are more nodes
		while (nextNodeToCheck != NULL) {
			HashMapNode* temp = nextNodeToCheck; //Save reference to next node before incrementing
			nextNodeToCheck = nextNodeToCheck->nextNode; //Move nextNode to next node
			nodeToCheck->nextNode = NULL; //Break link so I don't corrupt later nodes

			free(nodeToCheck->value);
			free(nodeToCheck->key);
			free(nodeToCheck);

			nodeToCheck = temp; //Update reference to next node
		}
	}

	//After deleting every index, we delete the map :) 
	free((*map)->arr);
	free((*map));
	*map = NULL;
}
#ifndef Array_List
#define Array_List
#define ArrayListStartSize 16

typedef struct {
	void* arr;
	int currMaxSize;
	int size;
	size_t elementSize;
} ArrayList;

ArrayList* initArrayList(size_t);

void alAdd(ArrayList*, void*);

void alAddAtIndex(ArrayList*, void*, int);

void alRemoveAtIndex(ArrayList*, int);

void alSetAtIndex(ArrayList*, void*, int);

void* alGetFromIndex(ArrayList*, int);

void alClear(ArrayList*);

void alResize(ArrayList*);

void alDelete(ArrayList*);

int alIsEmpty(ArrayList*);

#endif

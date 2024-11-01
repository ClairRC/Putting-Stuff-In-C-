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

void add(ArrayList*, void*);

void addAtIndex(ArrayList*, void*, int);

void removeAtIndex(ArrayList*, int);

void set(ArrayList*, void*, int);

void* get(ArrayList*, int);

void clearArrayList(ArrayList*);

void resize(ArrayList*);

void deleteArrayList(ArrayList*);

int arrayListIsEmpty(ArrayList*);

#endif

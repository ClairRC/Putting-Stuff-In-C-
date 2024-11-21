#include <stdio.h>
#include <string.h>
#include "Hash_Map.h"

int main() {
	HashMap* map = initHashMap();

	//printf("%d %d", hash("1") % 16, hash("10") % 16);

	int i[25] = {
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12,
		13,
		14,
		15,
		16,
		17,
		18,
		19,
		20,
		21,
		22,
		23,
		24,
		25
	};

	hmPut(map, "1", &i[0], sizeof(int));
	hmPut(map, "2", &i[1], sizeof(int));
	hmPut(map, "3", &i[2], sizeof(int));
	hmPut(map, "4", &i[3], sizeof(int));
	hmPut(map, "5", &i[4], sizeof(int));
	hmPut(map, "6", &i[5], sizeof(int));
	hmPut(map, "7", &i[6], sizeof(int));
	hmPut(map, "8", &i[7], sizeof(int));
	hmPut(map, "9", &i[8], sizeof(int));
	hmPut(map, "10", &i[9], sizeof(int));
	hmPut(map, "11", &i[10], sizeof(int));
	hmPut(map, "12", &i[11], sizeof(int));
	hmPut(map, "13", &i[12], sizeof(int));
	hmPut(map, "14", &i[13], sizeof(int));
	hmPut(map, "15", &i[14], sizeof(int));
	hmPut(map, "16", &i[15], sizeof(int));
	hmPut(map, "17", &i[16], sizeof(int));
	hmPut(map, "18", &i[17], sizeof(int));
	hmPut(map, "19", &i[18], sizeof(int));
	hmPut(map, "20", &i[19], sizeof(int));
	hmPut(map, "21", &i[20], sizeof(int));
	hmPut(map, "22", &i[21], sizeof(int));
	hmPut(map, "23", &i[22], sizeof(int));
	hmPut(map, "24", &i[23], sizeof(int));
	hmPut(map, "25", &i[24], sizeof(int));

	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "1")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "2")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "3")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "4")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "5")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "6")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "7")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "8")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "9")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "10")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "11")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "12")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "13")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "14")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "15")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "16")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "17")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "18")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "19")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "20")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "21")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "22")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "23")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "24")), map->size, map->currMaxSize);
	printf("Val: %d, Size: %d, Max Size: %d\n", *((int*)hmGetValueFromKey(map, "25")), map->size, map->currMaxSize);

	hmDelete(&map);

	if (map == NULL)
		printf("yay");
	else
		printf("booo");
	
	return 0;
}
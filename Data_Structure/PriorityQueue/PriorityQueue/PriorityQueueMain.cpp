#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

// function for determine priority of data, if length of string is shorter then data has higher priority
// input : two of string
// output : integer if first string has higher priority then bigger than 0, if second string has higher priority than smaller than 0, otherwise 0
int DataPriorityComp(const char* str1, const char* str2) {
	return strlen(str2) - strlen(str1);
}

int main() {
	Queue que;
	PQueueInit(&que, DataPriorityComp);

	Enqueue(&que, "apple");
	Enqueue(&que, "pine apple");
	Enqueue(&que, "banana");
	Enqueue(&que, "kiwi");
	Enqueue(&que, "tomato");

	while (!QIsEmpty(&que))
		printf("%s\n", Dequeue(&que));

	return 0;
}
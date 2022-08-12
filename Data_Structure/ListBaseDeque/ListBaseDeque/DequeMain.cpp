#include <stdio.h>
#include "Deque.h"

int main() {
	Deque deq;
	DequeInit(&deq);

	DQAddFirst(&deq, 3); DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4); DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	printf("Get First : %d\n", DQGetFirst(&deq));
	printf("Get Last : %d\n", DQGetLast(&deq));

	printf("Remove First : ");
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));
	printf("\n");

	DQAddFirst(&deq, 3); DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4); DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	printf("Remove Last : ");
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));
	printf("\n");

	return 0;
}
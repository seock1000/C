#include <stdio.h>
#include "CircularQueue.h"

int main() {
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5);

	printf("Peek : %d\n", QPeek(&q));
	printf("Dequeue : ");
	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));
	printf("\n");

	return 0;
}
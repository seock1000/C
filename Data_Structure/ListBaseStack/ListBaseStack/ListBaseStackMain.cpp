#include <stdio.h>
#include "ListBaseStack.h"

int main() {
	Stack stack;
	StackInit(&stack);

	// Push
	for (int i = 1; i <= 5; i++)
		SPush(&stack, i);

	// Peek
	printf("Peek : %d\n", SPeek(&stack));

	// Pop
	printf("Pop : ");
	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}
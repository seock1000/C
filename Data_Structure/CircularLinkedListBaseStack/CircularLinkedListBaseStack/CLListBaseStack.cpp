#include <stdio.h>
#include <stdlib.h>
#include "CLListBaseStack.h"
#include "CLinkedList.h"

void StackInit(Stack* pstack) {
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack* pstack) {
	if (LCount(pstack->plist) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack) {
	Data data;

	// 스택이 비었을 경우
	if (!LFirst(pstack->plist, &data)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	LRemove(pstack->plist);

	return data;
}

Data SPeek(Stack* pstack) {
	Data data;

	// 스택이 비었을 경우
	if (!LFirst(pstack->plist, &data)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return data;
}
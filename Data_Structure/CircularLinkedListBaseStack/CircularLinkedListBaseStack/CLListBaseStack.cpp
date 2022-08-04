#include <stdio.h>
#include <stdlib.h>
#include "CLListBaseStack.h"
#include "CLinkedList.h"

void StackInit(Stack* pstack) {
	ListInit(pstack); // 스택을 빈 상태로 초기화
}

int SIsEmpty(Stack* pstack) {
	Data data;
	return !(LFirst(pstack, &data));
}

void SPush(Stack* pstack, Data data) {
	LInsertFront(pstack, data);
}

Data SPop(Stack* pstack) {
	Data rdata;

	// 스택이 비었을 경우
	if (!LFirst(pstack, &rdata)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	LRemove(pstack);

	return rdata;
}

Data SPeek(Stack* pstack) {
	Data rdata;

	// 스택이 비었을 경우
	if (!LFirst(pstack, &rdata)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return rdata;
}
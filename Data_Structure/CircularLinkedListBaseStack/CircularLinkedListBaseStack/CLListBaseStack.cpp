#include <stdio.h>
#include <stdlib.h>
#include "CLListBaseStack.h"
#include "CLinkedList.h"

void StackInit(Stack* pstack) {
	ListInit(pstack); // ������ �� ���·� �ʱ�ȭ
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

	// ������ ����� ���
	if (!LFirst(pstack, &rdata)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	LRemove(pstack);

	return rdata;
}

Data SPeek(Stack* pstack) {
	Data rdata;

	// ������ ����� ���
	if (!LFirst(pstack, &rdata)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return rdata;
}
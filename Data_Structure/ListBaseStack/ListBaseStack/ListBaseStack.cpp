#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL; // ������ �� ����(head�� NULL)�� �ʱ�ȭ
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL) // ������ ������� Ȯ��
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // ��� ����
	newNode->data = data; // ��忡 ������ ����

	// �Ӹ� �κп� �� ��� �߰�
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack* pstack) {
	Node* rNode; 
	Data rData;

	// ������ ����� ���
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	// ������ ����� �ּҿ� ������ �ӽ� ����
	rNode = pstack->head;
	rData = pstack->head->data;

	// ��� ����
	pstack->head = pstack->head->next;
	free(rNode);

	// ������ ������ ��ȯ
	return rData;
}

Data SPeek(Stack* pstack) {
	
	// ������ ����� ���
	if (SIsEmpty(pstack)) {
		printf("Memory Error!");
		exit(-1);
	}

	// ������ ������ ��ȯ
	return pstack->head->data;
}
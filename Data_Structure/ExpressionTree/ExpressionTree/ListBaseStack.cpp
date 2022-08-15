#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack) {
	pstack->head = NULL; // 스택이 빈 상태(head가 NULL)로 초기화
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL) // 스택이 비었는지 확인
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 노드 생성
	newNode->data = data; // 노드에 데이터 저장

	// 머리 부분에 새 노드 추가
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack* pstack) {
	Node* rNode; 
	Data rData;

	// 스택이 비었을 경우
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	// 마지막 노드의 주소와 데이터 임시 저장
	rNode = pstack->head;
	rData = pstack->head->data;

	// 노드 삭제
	pstack->head = pstack->head->next;
	free(rNode);

	// 삭제된 데이터 반환
	return rData;
}

Data SPeek(Stack* pstack) {
	
	// 스택이 비었을 경우
	if (SIsEmpty(pstack)) {
		printf("Memory Error!");
		exit(-1);
	}

	// 마지막 데이터 반환
	return pstack->head->data;
}
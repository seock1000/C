#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) { // 꼬리 부분에 노드 추가
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next; // 새 노드와 머리를 연결
		plist->tail->next = newNode; // 기존 리스트의 꼬리와 새 노드를 연결
		plist->tail = newNode; // 포인터 변수 tail이 새 노드를 가리킴
	}
	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data) { // 머리 부분에 노드 추가
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next; // 새 노드와 머리를 연결
		plist->tail->next = newNode; // 꼬리와 새 노드를 연결(새 노드가 머리 부분에 추가)
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->cur = plist->tail->next; // cur이 머리를 가리킴
	plist->before = plist->tail; // before이 cur의 이전 노드(=꼬리)를 가리킴
	
	*pdata = plist->cur->data; // cur이 가리키는 데이터 전달	
	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur; // before이 cur을 가리킴
	plist->cur = plist->cur->next; // cur이 그 다음 노드를 가리킴

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist) {
	Data rdata = plist->cur->data;

	if (plist->cur == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}
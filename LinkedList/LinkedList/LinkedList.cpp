#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드 생성
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next; // 새 노드에 head(더미 노드)가 가리키는 노드 연결
	plist->head->next = newNode; // 더미 노드에 새 노드 연결

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;

	// 새 노드가 들어갈 위치 탐색(새 노드가 비교대상인 노드 보다 앞순서이면 0 반환)
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}
	// pred 다음 노드에 newNode 삽입
	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL) // 정렬 기준이 없는 경우
		FInsert(plist, data);
	else // 정렬 기준이 있는 경우
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}
// before에 왜 저장하는지? -> before에 저장해놔야 삭제하는 경우 이전 노드와 다음 노드 연결 가능


LData LRemove(List* plist) {
	Node* rpos = plist->cur; // 소멸대상의 주소 값 저장
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next; // 소멸대상 리스트에서 제거
	plist->cur = plist->before; // cur이 가리키는 위치 조정

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}
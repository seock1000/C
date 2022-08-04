#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) { // ���� �κп� ��� �߰�
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next; // �� ���� �Ӹ��� ����
		plist->tail->next = newNode; // ���� ����Ʈ�� ������ �� ��带 ����
		plist->tail = newNode; // ������ ���� tail�� �� ��带 ����Ŵ
	}
	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data) { // �Ӹ� �κп� ��� �߰�
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next; // �� ���� �Ӹ��� ����
		plist->tail->next = newNode; // ������ �� ��带 ����(�� ��尡 �Ӹ� �κп� �߰�)
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->cur = plist->tail->next; // cur�� �Ӹ��� ����Ŵ
	plist->before = plist->tail; // before�� cur�� ���� ���(=����)�� ����Ŵ

	*pdata = plist->cur->data; // cur�� ����Ű�� ������ ����	
	return TRUE;
}

int LNext(List* plist, Data* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur; // before�� cur�� ����Ŵ
	plist->cur = plist->cur->next; // cur�� �� ���� ��带 ����Ŵ

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data rdata = plist->cur->data;

	if (plist->cur == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData;
}
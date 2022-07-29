#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Point.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node)); // ���� ��� ����
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next; // �� ��忡 head(���� ���)�� ����Ű�� ��� ����
	plist->head->next = newNode; // ���� ��忡 �� ��� ����

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;

	// �� ��尡 �� ��ġ Ž��(�� ��尡 �񱳴���� ��� ���� �ռ����̸� 0 ��ȯ)
	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}
	// pred ���� ��忡 newNode ����
	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data) {
	if (plist->comp == NULL) // ���� ������ ���� ���
		FInsert(plist, data);
	else // ���� ������ �ִ� ���
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
// before�� �� �����ϴ���? -> before�� �����س��� �����ϴ� ��� ���� ���� ���� ��� ���� ����


LData LRemove(List* plist) {
	Node* rpos = plist->cur; // �Ҹ����� �ּ� �� ����
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next; // �Ҹ��� ����Ʈ���� ����
	plist->cur = plist->before; // cur�� ����Ű�� ��ġ ����

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
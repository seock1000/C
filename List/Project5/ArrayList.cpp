#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
	plist->countData = 0; // ����� �������� �� �ʱ�ȭ
	plist->point = -1; // ���� ����Ű�� ��ġ �ʱ�ȭ(-1�� ����Ű�� ������ �ǹ�)
}

void LInsert(List* plist, LData data) {
	if (plist->countData >= LIST_LEN) {
		printf("There is no space to insert\n");
		return;
	}
	plist->arr[plist->countData] = data; // ������ ����
	plist->countData++; // ����� �������� �� ����
}

int LFirst(List* plist, LData* pdata) {
	if (plist->countData == 0) { // ����� �����Ͱ� ������ FALSE ��ȯ
		return FALSE;
	}
	// ����� �����Ͱ� �ִ� ���
	plist->point = 0; // ���� ��ġ �ʱ�ȭ
	*pdata = plist->arr[0]; // pdata�� ����Ű�� ������ ������ ����
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->point >= plist->countData - 1) { // ������ �����Ͱ� ������ FALSE ��ȯ
		return FALSE;
	}
	// ����� �����Ͱ� �ִ� ���
	plist->point++; // ���� ��ġ +1
	*pdata = plist->arr[plist->point]; // pdata�� ����Ű�� ������ ������ ����
	return TRUE;
}

LData LRemove(List* plist) {
	LData data;
	data = plist->arr[plist->point]; // ������ ������ �ӽ� ����

	for (int i = plist->point; i < plist->countData; i++) {
		plist->arr[i] = plist->arr[i + 1];
	} // �ݺ����� ���� ������ ������ ������ �����͸� ������ �̵�
	plist->point--; // ���� ��ġ ����
	plist->countData--; // �������� �� ����
	return data; // ������ ������ ��ȯ
}

int LCount(List* plist) {
	return plist->countData;
}
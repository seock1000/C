#ifndef __Array__List__H
#define __Array__List__H

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100 // �迭�� ���� ��ũ�� ����

#include "StructureList.h"

typedef Point* LData;

typedef struct __ArrayList {
	LData arr[LIST_LEN]; // ����Ʈ ���� �迭
	int countData; // ����� �������� ���� ���� ����
	int point; // �������� ������ġ ���� ����
} ArrayList;

typedef ArrayList List; // ArrayList�� List��� �̸� �ο�

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);

#endif
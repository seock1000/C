#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include "Point.h"

#define TRUE 1
#define FALSE 0

typedef Point* LData;

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head; // 더미노드 포인터
	Node* cur; // 참조 및 삭제
	Node* before; // 삭제
	int numOfData; // 저장된 데이터 수
	int (*comp)(LData d1, LData d2); // 정렬의 기준
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));

#endif

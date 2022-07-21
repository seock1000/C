#ifndef __Array__List__H
#define __Array__List__H

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100 // 배열의 길이 매크로 정의

#include "NameCard.h"

typedef NameCard* LData;

typedef struct __ArrayList {
	LData arr[LIST_LEN]; // 리스트 저장 배열
	int countData; // 저장된 데이터의 개수 저장 변수
	int point; // 데이터의 참조위치 저장 변수
} ArrayList;

typedef ArrayList List; // ArrayList에 List라는 이름 부여

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);

#endif
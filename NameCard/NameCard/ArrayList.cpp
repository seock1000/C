#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
	plist->countData = 0; // 저장된 데이터의 수 초기화
	plist->point = -1; // 현재 가리키는 위치 초기화(-1은 가리키지 않음을 의미)
}

void LInsert(List* plist, LData data) {
	if (plist->countData >= LIST_LEN) {
		printf("There is no space to insert\n");
		return;
	}
	plist->arr[plist->countData] = data; // 데이터 저장
	plist->countData++; // 저장된 데이터의 수 증가
}

int LFirst(List* plist, LData* pdata) {
	if (plist->countData == 0) { // 저장된 데이터가 없으면 FALSE 반환
		return FALSE;
	}
	// 저장된 데이터가 있는 경우
	plist->point = 0; // 참조 위치 초기화
	*pdata = plist->arr[0]; // pdata가 가리키는 공간에 데이터 저장
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->point >= plist->countData - 1) { // 참조할 데이터가 없으면 FALSE 반환
		return FALSE;
	}
	// 저장된 데이터가 있는 경우
	plist->point++; // 참조 위치 +1
	*pdata = plist->arr[plist->point]; // pdata가 가리키는 공간에 데이터 저장
	return TRUE;
}

LData LRemove(List* plist) {
	LData data;
	data = plist->arr[plist->point]; // 삭제할 데이터 임시 저장

	for (int i = plist->point; i < plist->countData; i++) {
		plist->arr[i] = plist->arr[i + 1];
	} // 반복문을 통해 삭제할 데이터 이후의 데이터를 앞으로 이동
	plist->point--; // 참조 위치 감소
	plist->countData--; // 데이터의 수 감소
	return data; // 삭제된 데이터 반환
}

int LCount(List* plist) {
	return plist->countData;
}
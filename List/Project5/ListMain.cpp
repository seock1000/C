#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "StructureList.h"

int main() {
	List list;
	Point compPos;
	Point* ppos;

	ListInit(&list); // 리스트 초기화

	// 데이터 저장
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// 저장된 데이터 출력
	printf("The number of current data : %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos가 2인 데이터 삭제
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		if (PointComp(ppos, &compPos) == 1) {
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos)) {
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// 삭제 후 남은 데이터 출력
	printf("The number of current data : %d\n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int WhoIsPrecede(LData d1, LData d2) {
	if (d1->xpos < d2->xpos)
		return 0;
	else if (d1->xpos == d2->xpos) {
		if (d1->ypos < d2->ypos)
			return 0;
		else
			return 1;
	}
	else 
		return 1;
}

int main() {
	List list;
	LData data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // ������ ���� ���

	data = (LData)malloc(sizeof(Point));
	SetPointPos(data, 1, 1);
	LInsert(&list, data);
	data = (LData)malloc(sizeof(Point));
	SetPointPos(data, 1, 2); 
	LInsert(&list, data);
	data = (LData)malloc(sizeof(Point));
	SetPointPos(data, 2, 2);
	LInsert(&list, data); 
	data = (LData)malloc(sizeof(Point));
	SetPointPos(data, 2, 1);
	LInsert(&list, data);
	data = (LData)malloc(sizeof(Point));
	SetPointPos(data, 3, 1);
	LInsert(&list, data);

	printf("���� �������� �� : %d\n", LCount(&list));
	// ������ ��ü ���
	if (LFirst(&list, &data)) {
		ShowPointPos(data);

		while (LNext(&list, &data)) {
			ShowPointPos(data);
		}
	}
	printf("\n\n");
	// xpos�� 2�� ������ ����
	if (LFirst(&list, &data)) {
		if (data->xpos == 2)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data->xpos == 2)
				LRemove(&list);
		}
	}
	printf("\n\n");

	printf("���� �������� �� : %d\n", LCount(&list));
	// ������ ��ü ���
	if (LFirst(&list, &data)) {
		ShowPointPos(data);

		while (LNext(&list, &data)) {
			ShowPointPos(data);
		}
	}
	printf("\n\n");

	return 0;
}
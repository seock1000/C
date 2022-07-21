#include <stdio.h>
#include "StructureList.h"

void SetPointPos(Point* ppos, int xpos, int ypos) { // ����
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos) { // ���
	printf("x : %d, ", ppos->xpos);
	printf("y : %d\n\n", ppos->ypos);
}

int PointComp(Point* ppos1, Point* ppos2) { // ��(xpos�� ����(1), ypos�� ����(2), ��� ����(0), ��� ����(-1))
	if (ppos1->xpos == ppos2->xpos) {
		if (ppos1->ypos == ppos2->ypos)
			return 0;
		else
			return 1;

	}
	else if (ppos1->ypos == ppos2->ypos)
		return 2;
	else
		return -1;
}
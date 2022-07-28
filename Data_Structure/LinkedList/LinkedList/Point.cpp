#include <stdio.h>
#include "Point.h"

void SetPointPos(Point* ppos, int xpos, int ypos) { // 저장
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos) { // 출력
	printf("x : %d, ", ppos->xpos);
	printf("y : %d\n\n", ppos->ypos);
}

int PointComp(Point* ppos1, Point* ppos2) { // 비교(xpos만 동일(1), ypos만 동일(2), 모두 동일(0), 모두 상이(-1))
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
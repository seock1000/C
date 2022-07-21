#ifndef __STRUCTURE_LIST_H__
#define __STRUCTURE_LIST_H__

typedef struct _point {
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point* ppos, int xpos, int ypos); // 저장
void ShowPointPos(Point* ppos); // 출력
int PointComp(Point* ppos1, Point* ppos2); // 비교(xpos만 동일(1), ypos만 동일(2), 모두 동일(0), 모두 상이(-1))

#endif

#ifndef __STRUCTURE_LIST_H__
#define __STRUCTURE_LIST_H__

typedef struct _point {
	int xpos;
	int ypos;
} Point;

void SetPointPos(Point* ppos, int xpos, int ypos); // ����
void ShowPointPos(Point* ppos); // ���
int PointComp(Point* ppos1, Point* ppos2); // ��(xpos�� ����(1), ypos�� ����(2), ��� ����(0), ��� ����(-1))

#endif

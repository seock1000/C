#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\..\CircularQueue\CircularQueue\CircularQueue.h"

#define CUS_COME_TERM 15 // ���� �ֹ� ����

#define CHE_BUR 0 // ġ����� ���
#define BUL_BUR 1 // �Ұ����� ���
#define DUB_BUR 2 // ������� ���

#define CHE_TERM 12 // ġ����� ���� �ð�
#define BUL_TERM 15 // �Ұ����� ���� �ð�
#define DUB_TERM 24 // ������� ���� �ð�

int main() {
	int makeProc = 0;// ���� ���� ���� ��Ȳ
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que; // ��⿭ �ǹ�

	QueueInit(&que);
	srand(time(NULL));

	// for���� 1ȸ �ݺ��� 1���� �帧 �ǹ�
	for (sec = 0; sec < 3600; sec++) {
		if (sec % CUS_COME_TERM == 0) {
			switch (rand() % 3) { // �ֹ��� ��������
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheOrder++;
				break;
			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulOrder++;
				break;
			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder++;
				break;
			}
		}
		
		if (makeProc <= 0 && !QIsEmpty(&que)) // ������ �Ϸ� �Ǿ���, ���� �ֹ��� ������
			makeProc = Dequeue(&que); // ���� �ֹ��� ���� ����

		makeProc--;
	}
	
	printf("Simulation Report!\n");
	printf(" - Cheese Burger : %d\n", cheOrder);
	printf(" - Bulgogi Burger : %d\n", bulOrder);
	printf(" - Double Burger : %d\n", dubOrder);
	printf(" - Waiting room size : %d\n", QUE_LEN);

	return 0;
}


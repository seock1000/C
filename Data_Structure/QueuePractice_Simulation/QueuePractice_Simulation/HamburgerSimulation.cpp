#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\..\CircularQueue\CircularQueue\CircularQueue.h"

#define CUS_COME_TERM 15 // 고객의 주문 간격

#define CHE_BUR 0 // 치즈버거 상수
#define BUL_BUR 1 // 불고기버거 상수
#define DUB_BUR 2 // 더블버거 상수

#define CHE_TERM 12 // 치즈버거 제조 시간
#define BUL_TERM 15 // 불고기버거 제조 시간
#define DUB_TERM 24 // 더블버거 제조 시간

int main() {
	int makeProc = 0;// 버거 제조 진행 상황
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que; // 대기열 의미

	QueueInit(&que);
	srand(time(NULL));

	// for문의 1회 반복은 1초의 흐름 의미
	for (sec = 0; sec < 3600; sec++) {
		if (sec % CUS_COME_TERM == 0) {
			switch (rand() % 3) { // 주문은 무작위로
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
		
		if (makeProc <= 0 && !QIsEmpty(&que)) // 제조가 완료 되었고, 남은 주문이 있으면
			makeProc = Dequeue(&que); // 다음 주문에 대한 제조

		makeProc--;
	}
	
	printf("Simulation Report!\n");
	printf(" - Cheese Burger : %d\n", cheOrder);
	printf(" - Bulgogi Burger : %d\n", bulOrder);
	printf(" - Double Burger : %d\n", dubOrder);
	printf(" - Waiting room size : %d\n", QUE_LEN);

	return 0;
}


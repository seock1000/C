#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 5

// 구조체 정의
struct NODE {
	int key;
	struct NODE* next; // 링크를 위한 포인터 변수
};

void main() {
	struct NODE node[NUM]; // 구조체 배열 선언

	// 구조체 배열의 각 요소 초기화
	for (int i = 0; i < NUM; i++) {
		node[i].key = i;
		node[i].next = NULL; // 포인터는 NULL로 초기화
	}

	// 구조체 배열의 각 요소의 멤버 출력
	printf("Before linking\n");
	for (int i = 0; i < NUM; i++) {
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
	}

	// 구조체 배열의 각 요소를 다음 요소에 link(마지막 요소는 다음 요소가 없으므로 제외)
	for (int i = 0; i < NUM - 1; i++) {
		node[i].next = &node[i + 1];
	}

	// 구조체 배열의 각 요소의 멤버 출력
	printf("\nAfter linking\n");
	for (int i = 0; i < NUM; i++) {
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
	}
}
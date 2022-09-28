#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 5

// ����ü ����
struct NODE {
	int key;
	struct NODE* next; // ��ũ�� ���� ������ ����
};

void main() {
	struct NODE node[NUM]; // ����ü �迭 ����

	// ����ü �迭�� �� ��� �ʱ�ȭ
	for (int i = 0; i < NUM; i++) {
		node[i].key = i;
		node[i].next = NULL; // �����ʹ� NULL�� �ʱ�ȭ
	}

	// ����ü �迭�� �� ����� ��� ���
	printf("Before linking\n");
	for (int i = 0; i < NUM; i++) {
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
	}

	// ����ü �迭�� �� ��Ҹ� ���� ��ҿ� link(������ ��Ҵ� ���� ��Ұ� �����Ƿ� ����)
	for (int i = 0; i < NUM - 1; i++) {
		node[i].next = &node[i + 1];
	}

	// ����ü �迭�� �� ����� ��� ���
	printf("\nAfter linking\n");
	for (int i = 0; i < NUM; i++) {
		printf("i=%d key=%d next=%d Add=%d\n", i, node[i].key, node[i].next, &node[i]);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NAME_LEN 64
#define NUM 2

// ����ü ����
struct student {
	char name[20];
	int height;
	float weight;
	int schols;
};

// call by reference, ������ ���� ȣ��
// �Ķ���ͷ� ����ü ������ ������ ����
// ��, �ּ� ���� �̿��ϹǷ� ���ڷ� ���� �ּҿ� ����� ���� �Լ� ������ ���� ����
void func(struct student* stu) {
	// ���ǿ� �°� ����, stu->height == (*stu).height
	if (stu->height < 180) stu->height = 180;
	if (stu->weight < 100) stu->weight = 100;
	// �ּҰ��� ����� ���� �����ϹǷ� ��ȯ ���� �ʿ����
}

int main() {
	struct student stu[NUM]; // ����ü �迭 ����

	// ����ü �迭�� ��ҿ� �� �Է�
	for (int i = 0; i < NUM; i++) {
		printf("Type %d-th student's into (Name, height, weight, schols) : ", i);
		scanf("%s %d %f %d", &stu[i].name, &stu[i].height, &stu[i].weight, &stu[i].schols);
	}

	// ���ǿ� �°� ����ü ����� �� ����
	for (int i = 0; i < NUM; i++)
		func(&stu[i]); // ����ü �迭�� �� ����� �ּҰ� ����

	// ��� ���
	for (int i = 0; i < NUM; i++) {
		printf("Name    = %10s\n", stu[i].name);
		printf("Height  = %10d\n", stu[i].height);
		printf("Weight  = %10f\n", stu[i].weight);
		printf("Schols  = %10d\n\n", stu[i].schols);
	}

	return 0;
}
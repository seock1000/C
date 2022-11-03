#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>

struct EMP { // EMP ����ü ����
	int RRN;
	char name[20];
	float salary; 
	float bonus;
}; 

// ������ �Էµ� ������ �� ���� �Էµ� �����Ϳ� ���� RRN�� �����ϴ��� Ȯ��
// input : EMP �迭, ���� �Էµ� ������, �迭�� ����� �������� ��
// output : ���� �����Ͱ� �����ϸ� 1 ��ȯ, �׷��� �ʴٸ� 0 ��ȯ
int check_prev(struct EMP* arr, struct EMP emp, int count) {
	for (int i = 0; i < count; i++) {
		if (arr[i].RRN == emp.RRN)
			return 1;
	}
	return 0;
}

int main() {
	struct EMP employee[MAX]; // MAX ���̷� EMP ����ü �迭 ����
	int total_num = 0; // �Է¹��� �������� ���� ���� ����
	int register_num = 0; // ����� �������� ���� ���� ����
	printf("Type the number of employees : ");
	scanf("%d", &total_num);

	// total_num��ŭ �ݺ�
	for (int i = 0; i < total_num; i++) {
		struct EMP tmp; // constraint �˻��ϱ� �� �ӽ� ����� EMP ����ü ���� ����
		printf("\nType employee information(RRN, name, salary, bonus) : ");
		scanf("%d %s %f %f", &tmp.RRN, &tmp.name, &tmp.salary, &tmp.bonus); // ������ �Է�

		// check_prev �Լ� ȣ��, RRN�� ���� �����Ͱ� ������ ����
		if (check_prev(employee, tmp, register_num)) {
			printf("Error : the RRN is already registered!\n\n");
		}
		// bonus�� salary ���� ũ�ų� ���ٸ� ����
		else if (tmp.bonus >= tmp.salary) {
			printf("Error : the bonus must be less than salary!\n\n");
		}
		// �������ǿ� �ɸ��� �ʴ´ٸ� �Է¹��� �����͸� array�� ����
		else {
			printf("The employee has been registered!\n\n");
			employee[register_num] = tmp;
			register_num++; // array�� ����� �������� ���� 1 ����
		}
	}

	// array�� ����� ������ ���
	for (int i = 0; i < register_num; i++) {
		printf("%d-th employee: RRN=%d Name=%s Salary=%f Bonus=%f\n", i, employee[i].RRN, employee[i].name, employee[i].salary, employee[i].bonus);
	}
	
	return 0;
}


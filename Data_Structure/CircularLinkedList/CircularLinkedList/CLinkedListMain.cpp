#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "PersonInformation.h"

#define TRUE 1
#define FALSE 0

int IfExist(List* plist, char* name);
void FindPerson(List* plist, int after);

int main() {
	List list;
	char name[100], compName[100];
	int number, after;
	ListInit(&list);

	// ������ �Է�
	for (;;) {
		printf("����� �̸� �Է�(�������� ������� 0)\n");
		printf("��� : ");
		scanf_s("%d", &number);
		if (number == 0)
			break;
		printf("�̸� : ");
		scanf_s("%s", name, 100);
		LInsert(&list, SetPersonInfo(number, name));
	}
	printf("\n");
	printf("�̸��� Ȯ���� ��¥�� �Է�\n");
	printf("�̸� : ");
	scanf_s("%s", compName, 100);
	printf("��¥ : ");
	scanf_s("%d", &after);

	if (IfExist(&list, compName)) {
		FindPerson(&list, after);
		printf("%s ���� %d�� ���� ������\n", compName, after);
		PrintInfo(list.cur->data);
	}
	else
		printf("�������� �ʴ� ����Դϴ�.\n");
	// ifExist�� FindNextPerson���� �ٲ㼭 ¥��
	return 0;
}


int IfExist(List* plist, char* name) {
	Data data = (Data)malloc(sizeof(Person));
	int i;
	if (LFirst(plist, &data)) {
		if (CompPersonInfo(data, name) == 0) {
			free(data);
			return TRUE;
		}

		for (i = 0; i < LCount(plist) - 1; i++) {
			LNext(plist, &data);
			if (CompPersonInfo(data, name) == 0) {
				free(data);
				return TRUE;
			}
		}
	}
	free(data);
	return FALSE;
}

void FindPerson(List* plist, int after) {
	Data data;
	int i;
	for (i = 0; i < after; i++)
		LNext(plist, &data);
}

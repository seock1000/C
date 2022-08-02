#include <stdio.h>
#include <string.h>
#include "DBLinkedList.h"

int main() {
	// ����Ʈ ���� �� �ʱ�ȭ
	List list;
	Data data;
	int mode;
	ListInit(&list);

	do {
		printf("1. �Է�\n2. ����\n3. ��ü ���\n0. ����\n");
		printf("--------------------------------------\n");
		printf("�Է� : ");
		scanf_s("%d", &mode);
		switch (mode) {
		
		case 1:
			int number;
			char name[100];
			printf("��ȣ�� �̸��� �Է��ϼ���.\n");
			printf("��ȣ : ");
			scanf_s("%d", &number);
			printf("�̸� : ");
			scanf_s("%s", name, 100);
			LInsert(&list, setPersonInfo(name, number));
			break;
		
		case 2:
			printf("������ ��ȣ�� �̸��� �Է��ϼ���.\n");
			printf("��ȣ : ");
			scanf_s("%d", &number);
			printf("�̸� : ");
			scanf_s("%s", name, 100);
			if (LFirst(&list, &data)) {
				if (compPerson(data, name, number)) {
					printPersonInfo(data);
					LRemove(&list);
					printf("���� �Ǿ����ϴ�.\n");
				}

				while (LNext(&list, &data)) {
					if (compPerson(data, name, number)) {
						printPersonInfo(data);
						LRemove(&list);
						printf("���� �Ǿ����ϴ�.\n");
					}
				}
			}
			break;
		
		case 3:
			if (LFirst(&list, &data)) {
				printPersonInfo(data);

				while (LNext(&list, &data))
					printPersonInfo(data);

				printf("\n\n");
			}
			break;
		
		case 0:
			printf("���α׷��� �����մϴ�.\n");
			break;
		
		default :
			printf("�߸��� �Է��Դϴ�.\n");
			continue;
		}
	} while (mode != 0);

	return 0;
}
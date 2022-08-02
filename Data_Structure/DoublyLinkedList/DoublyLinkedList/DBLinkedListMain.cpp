#include <stdio.h>
#include <string.h>
#include "DBLinkedList.h"

int main() {
	// 리스트 생성 및 초기화
	List list;
	Data data;
	int mode;
	ListInit(&list);

	do {
		printf("1. 입력\n2. 삭제\n3. 전체 출력\n0. 종료\n");
		printf("--------------------------------------\n");
		printf("입력 : ");
		scanf_s("%d", &mode);
		switch (mode) {
		
		case 1:
			int number;
			char name[100];
			printf("번호와 이름을 입력하세요.\n");
			printf("번호 : ");
			scanf_s("%d", &number);
			printf("이름 : ");
			scanf_s("%s", name, 100);
			LInsert(&list, setPersonInfo(name, number));
			break;
		
		case 2:
			printf("삭제할 번호와 이름을 입력하세요.\n");
			printf("번호 : ");
			scanf_s("%d", &number);
			printf("이름 : ");
			scanf_s("%s", name, 100);
			if (LFirst(&list, &data)) {
				if (compPerson(data, name, number)) {
					printPersonInfo(data);
					LRemove(&list);
					printf("삭제 되었습니다.\n");
				}

				while (LNext(&list, &data)) {
					if (compPerson(data, name, number)) {
						printPersonInfo(data);
						LRemove(&list);
						printf("삭제 되었습니다.\n");
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
			printf("프로그램을 종료합니다.\n");
			break;
		
		default :
			printf("잘못된 입력입니다.\n");
			continue;
		}
	} while (mode != 0);

	return 0;
}
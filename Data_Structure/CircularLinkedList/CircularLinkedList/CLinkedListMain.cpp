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

	// 데이터 입력
	for (;;) {
		printf("사번과 이름 입력(끝내려면 사번에서 0)\n");
		printf("사번 : ");
		scanf_s("%d", &number);
		if (number == 0)
			break;
		printf("이름 : ");
		scanf_s("%s", name, 100);
		LInsert(&list, SetPersonInfo(number, name));
	}
	printf("\n");
	printf("이름과 확인할 날짜를 입력\n");
	printf("이름 : ");
	scanf_s("%s", compName, 100);
	printf("날짜 : ");
	scanf_s("%d", &after);

	if (IfExist(&list, compName)) {
		FindPerson(&list, after);
		printf("%s 님의 %d일 이후 당직은\n", compName, after);
		PrintInfo(list.cur->data);
	}
	else
		printf("존재하지 않는 사원입니다.\n");
	// ifExist랑 FindNextPerson으로 바꿔서 짜기
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

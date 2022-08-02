#include <stdio.h>
#include <string.h>
#include "PersonInfo.h"

void setPersonInfo(Person* p, char* name, int number) {
	strcpy_s(p->name, name);
	p->number = number;
}

int compPerson(Person* p, char* name, int number) {
	if ((strcmp(p->name, name) == 0) && (p->number == number))
		return 1;
	return 0;
}

void printPersonInfo(Person* p) {
	printf("이름 : %s\n", p->name);
	printf("번호 : %d\n", p->number);
	printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PersonInfo.h"

Person* setPersonInfo(char* name, int number) {
	Person* p = (Person*)malloc(sizeof(Person));
	strcpy_s(p->name, name);
	p->number = number;
	
	return p;
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
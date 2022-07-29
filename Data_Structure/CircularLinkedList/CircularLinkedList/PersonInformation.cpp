#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PersonInformation.h"


Person* SetPersonInfo(int number, char* name) {
	Person* person = (Person*)malloc(sizeof(Person));
	person->number = number;
	strcpy_s(person->name, name);

	return person;
}

int CompPersonInfo(Person* pperson, char* name) {
	return strcmp(pperson->name, name);
}

void RemoveInfo(Person* pperson) {
	free(pperson);
}

void PrintInfo(Person* pperson) {
	printf("��� : %d, ", pperson->number);
	printf("�̸� : %s", pperson->name);
	printf("\n");
}


#ifndef __PERSON_INFORMATION__
#define __PERSON_INFORMATION__

typedef struct _person {
	int number;
	char name[100];
}Person;

typedef Person* Data;

Person* SetPersonInfo(int number, char* name);
int CompPersonInfo(Person* pperson, char* name);
void RemoveInfo(Person* pperson);
void PrintInfo(Person* pperson);


#endif

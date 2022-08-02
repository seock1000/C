
typedef struct _person {
	char name[100];
	int number;
} Person;

void setPersonInfo(Person* p, char* name, int number);
int compPerson(Person* p, char* name, int number);
void printPersonInfo(Person* p);



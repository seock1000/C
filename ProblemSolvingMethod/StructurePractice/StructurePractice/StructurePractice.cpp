#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
* declare structure as a variable
struct {
	char name[20];
	int age;
	float salary;
	char hobby[3][20];
} employee; // 메모리 공간에 해당 변수들이 연속적으로 할당

int main() {

	strcpy(employee.name, "kim");
	employee.age = 20;
	employee.salary = 10;

	printf("%s\n%d\n%.lf", employee.name, employee.age, employee.salary);

	return 0;
}
*/

/**
* declare structure as data type
struct _EMP {
	char name[20];
	int age;
	float salary;
	char hobby[3][20];
};

int main() {
	struct _EMP employee;

	strcpy(employee.name, "kim");
	employee.age = 20;
	employee.salary = 10;

	printf("%s\n%d\n%.lf", employee.name, employee.age, employee.salary);

	return 0;
}
*/

/**
* define point structure

typedef struct _point {
	int x;
	int y;
}Point;

*/

/**
//initialize structure with define
struct {
	int x;
	char c;
	int y;
} struc = {1, 'a', 2};
*/

// Excercise month, day, year

struct Birth{
	int month;
	int day;
	int year;
};

int main() {
	struct Birth birth;

	birth.month = 12;
	birth.day = 20;
	birth.year = 2003;

	printf("My birth date is %d/%d/%d", birth.year, birth.month, birth.day);

	return 0;
}
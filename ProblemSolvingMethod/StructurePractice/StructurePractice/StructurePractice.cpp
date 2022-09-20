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

/*
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
*/

/*
// Array of structure

struct {
	char name[20];
	char abbr[2];
	int population;
	float area;
	double GDP;
	char governor;
} US_State[50];

struct {
	char name[20];
	int age;
	float salary;
	char hobby[3][20];
} emplyee[300];

*/

/*
// Exercise1

struct MonthDays {
	char name[10];
	int days;
};

void InputMonthDays(struct MonthDays monthDays[]) {
	for (int i = 0; i < 12; i++) {
		printf("Type the information of Month Days (Name, days) : ");
		scanf("%s %d", monthDays[i].name, &monthDays[i].days);
	}
}

void PrintMonthDays(struct MonthDays monthDays[]) {
	for (int i = 0; i < 12; i++) {
		printf("%s days = %d\n", monthDays[i].name, monthDays[i].days);
	}
}

int main() {
	struct MonthDays monthDays[12];
	
	InputMonthDays(monthDays);
	
	PrintMonthDays(monthDays);
	
	return 0;
}
*/

// Exercise 2

typedef struct _worker {
	int ID;
	char name[20];
	float payRate;
	float workHour;
} Worker;

void InputData(Worker worker[]) {
	FILE* fp;
	if ((fp = fopen("input.txt", "r")) == NULL) {
		printf("file open failed!\n");
		exit(-1);
	}

	for (int i = 0; i < 6; i++) {
		//printf("Type the data(ID, Name, Pay Rate, Hours Worked) : ");
		fscanf(fp, "%d %s %f %f", &worker[i].ID, worker[i].name, &worker[i].payRate, &worker[i].workHour);
	}

	fclose(fp);
}

void PrintTotalPay(Worker worker[]) {
	float sum = 0;
	for (int i = 0; i < 6; i++) {
		printf("%d %s's total payment is %.1f\n", worker[i].ID, worker[i].name, worker[i].payRate * worker[i].workHour);
		sum += worker[i].payRate * worker[i].workHour;
	}
	printf("Total worker's payment is %.1f\n", sum);
}

int main() {	
	Worker worker[6];

	InputData(worker);
	PrintTotalPay(worker);

	return 0;
}
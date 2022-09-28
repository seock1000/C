#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _student {
	char name[20];
	int height;
	float weight;
	int schols;
} Student;

void PrintInfo(Student stu) {

}

int main() {
	Student stu[2];
	int i;

	for (i = 0; i < 2; i++) {
		printf("Type %d-th student's info (Name, height, weight, schols) : ");
		scanf("%s %d %f %d", stu[i].name, stu[i].height, stu[i].weight, stu[i].schols);
	}
}
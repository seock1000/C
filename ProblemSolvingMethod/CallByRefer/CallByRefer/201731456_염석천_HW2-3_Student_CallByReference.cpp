#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NAME_LEN 64
#define NUM 2

struct student {
	char name[20];
	int height;
	float weight;
	int schols;
};

// call by value
void func(struct student* stu) {
	if (stu->height < 180) stu->height = 180;
	if (stu->weight < 100) stu->weight = 100;
}

int main() {
	struct student stu[NUM];
	for (int i = 0; i < NUM; i++) {
		printf("Type %d-th student's into (Name, height, weight, schols) : ", i);
		scanf("%s %d %f %d", &stu[i].name, &stu[i].height, &stu[i].weight, &stu[i].schols);
	}

	for (int i = 0; i < NUM; i++)
		func(&stu[i]);


	for (int i = 0; i < NUM; i++) {
		printf("Name    = %10s\n", stu[i].name);
		printf("Height  = %10d\n", stu[i].height);
		printf("Weight  = %10f\n", stu[i].weight);
		printf("Schols  = %10d\n\n", stu[i].schols);
	}

	return 0;
}
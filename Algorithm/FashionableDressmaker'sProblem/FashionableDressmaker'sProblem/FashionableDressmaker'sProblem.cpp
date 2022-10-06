#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

void InputData(FILE* fp, int* time, int* fine, int n) {
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d", &time[i], &fine[i]);
	}
}

void main() {
	FILE* fp;
	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("File open failed!\n");
		exit(-1);
	}
	int n;

	fscanf(fp, "%d", &n);
	if (n < 1 || n > 1000) {
		printf("Wrong Input!\n");
		exit(-1);
	}

	while (n-- > 0) {
		int task;
		fgetc(fp);
		fscanf(fp, "%d", &task);
		int* time = (int*)malloc(sizeof(int) * task);
		int* fine = (int*)malloc(sizeof(int) * task);

		
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp = fopen("test.txt", "w");
	if (fp == NULL)
		exit(-1);

	fprintf(fp, "file output.");
	printf("Write file success!");
	return 0;
}
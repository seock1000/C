#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// copy the choosen file 
int main() {
	FILE* inputStream;
	FILE* outputStream;
	char inputFileName[100];
	char outputFileName[110];

	printf("Enter the file name to copy : ");
	scanf("%s", inputFileName);

	if ((inputStream = fopen(inputFileName, "r")) == NULL) {
		printf("Input File Open Failed!\n");
		exit(-1);
	}

	strcpy(outputFileName, inputFileName);
	strcat(outputFileName, "_copy.txt");
	
	if ((outputStream = fopen(outputFileName, "w")) == NULL) {
		printf("Input File Open Failed!\n");
		exit(-1);
	}

	char ch;

	while ((ch = fgetc(inputStream)) != EOF)
		fputc(ch, outputStream);

	printf("File Copy Complete!\n");

	fclose(inputStream);
	fclose(outputStream);

	return 0;
}
*/


// moving cursor

int main() {
	FILE* myinFile;
	int groupNum = 0;

	myinFile = fopen("sample_input.txt", "r");
	if (myinFile == NULL) {
		printf("File open failed!\n");
		exit(-1);
	}

	while (fscanf(myinFile, "%d", &groupNum) != EOF) {
		float sum = 0.0;
		int data = 0;
		for (int i = 0; i < groupNum; i++) {
			fscanf(myinFile, "%d", &data);
			sum += data;
		}
		printf("Average : %f\n", sum / groupNum);

		fclose(myinFile);
	}

	return 0;
}
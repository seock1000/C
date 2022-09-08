#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100

float* mile2km(int arr[]) {
	float* mileArr = (float*)malloc(sizeof(float) * MAX_NUM);

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		mileArr[i] = (float)arr[i] * 1.6093;

	return mileArr;
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	float* mileArr;

	mileArr = mile2km(arr);

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%f", mileArr[i]);

	free(mileArr);

	return 0;
}
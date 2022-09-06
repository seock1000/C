#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

#define MAT_SIZE 10

void FillMatrix(int matrix[][MAT_SIZE], int stepSize) {
	int i, j;
	int n = 0;

	for (i = 0; i < MAT_SIZE; i++) {
		for (j = 0; j < MAT_SIZE; j++) {
			matrix[i][j] = n;
			n += stepSize;
		}
	}
}

void MutiplyMatrix(int matrix1[][MAT_SIZE], int matrix2[][MAT_SIZE], int matrix3[][MAT_SIZE]) {

}

void printMatrix5Space() {

}

void printMatrix10Space() {

}

int main() {
	int matrix1[MAT_SIZE][MAT_SIZE];
	int matrix2[MAT_SIZE][MAT_SIZE];
	int matrix3[MAT_SIZE][MAT_SIZE];



}
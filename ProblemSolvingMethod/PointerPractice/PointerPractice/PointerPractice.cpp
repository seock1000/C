#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int inum = 205;
	double fnum = 375.42;
	
	int* a = &inum;
	double* b = &fnum;

	int** aPtr = &a;
	double** bPtr = &b;


	return 0;
}
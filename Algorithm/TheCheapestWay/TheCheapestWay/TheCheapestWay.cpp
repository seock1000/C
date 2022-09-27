#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 100

typedef struct _node {
	int data;
	int* seq;
}Node;

// input Matrix
void InputMat(int (*arr)[COL], int n, int m, FILE* fp) {

	if (n > 10 || m > 100) {
		printf("Wrong Input!\n");
		exit(-1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fp, "%d", &arr[i][j]);
		}
	}
}

// extend array and add value to array
int* ExtendArray(int* arrToCpy, int arrLen, int data) {
	int* arrToExtend;

	if (arrToCpy == NULL) {
		arrToExtend = (int*)malloc(sizeof(int));
		arrToExtend[0] = data;
	}

	else {
		arrToExtend = (int*)malloc(sizeof(int) * arrLen);
		for (int i = 0; i < arrLen - 1; i++) {
			arrToExtend[i] = arrToCpy[i];
		}
		arrToExtend[arrLen - 1] = data;
	}

	return arrToExtend;
}

// find min index
int FindMinIdx(Node* table[COL], int start, int end, int row_size, int curCol) {
	int min = table[start][curCol].data;
	int minIdx = start;
	int i;

	if (end < start) {
		for (i = start; i < row_size; i++) {
			if (min > table[i][curCol].data) {
				min = table[i][curCol].data;
				minIdx = i;
			}
		}
		for (i = 0; i <= end; i++) {
			if (min > table[i][curCol].data) {
				min = table[i][curCol].data;
				minIdx = i;
			}
		}
	}
	else {
		for (i = start; i <= end; i++) {
			if (min > table[i][curCol].data) {
				min = table[i][curCol].data;
				minIdx = i;
			}
		}
	}

	return minIdx;
}

// find cheapest way
int FindCheapWay(int (*arr)[COL], int row, int col) {

	int i, j;
	int rdata;
	Node** table = (Node**)malloc(sizeof(Node*) * row);

	for (i = 0; i < row; i++) {
		table[i] = (Node*)malloc(sizeof(Node) * col);
		table[i][0].data = arr[i][0];

		table[i][0].seq = ExtendArray(NULL, 1, arr[i][0]);

	}

	for (i = 1; i < col; i++) {
		for (j = 0; j < row; j++) {
			int minIdx = FindMinIdx(table, ((j + row - 1) % row), ((j + 1) % row), row, i - 1);

			table[j][i].data = table[minIdx][i - 1].data + arr[j][i];
			table[j][i].seq = ExtendArray(table[minIdx][i - 1].seq, i + 1, arr[j][i]);
		}
	}

	int minIdx = FindMinIdx(table, 0, row - 1, row, col - 1);

	for (i = 0; i < col; i++)
		printf("%d ", table[minIdx][col - 1].seq[i]);
	printf("\n");

	rdata = table[minIdx][col - 1].data;

	free(table);

	return rdata;
}

int main() {
	FILE* fp;

	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("file open failed!\n");
		exit(-1);
	}
	int arr[ROW][COL];
	int n, m;

	while (!feof(fp)) {
		fscanf(fp, "%d", &n);
		fscanf(fp, "%d", &m);
		InputMat(arr, n, m, fp);
		printf("%d\n", FindCheapWay(arr, n, m));
	}
	
	fclose(fp);

	return 0;
}
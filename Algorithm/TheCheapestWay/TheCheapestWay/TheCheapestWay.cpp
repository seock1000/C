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

// find min index
int FindMinIDX(Node* table[COL], int curRow, int curCol, int row) {
	int x = table[(curRow + row - 1) % row][curCol - 1].data;
	int y = table[curRow][curCol - 1].data;
	int z = table[(curRow + 1) % row][curCol - 1].data;

	int min = x;
	int minIdx = (curRow + row - 1) % row;

	if (y < min) {
		min = y;
		minIdx = curRow;
	}

	if (z < min) {
		min = z;
		minIdx = (curRow + 1) % row;
	}

	return minIdx;
}

// find cheapest way
void FindCheapWay(int (*arr)[COL], int row, int col) {

	int i, j;
	Node** table = (Node**)malloc(sizeof(Node*) * row);

	for (i = 0; i < row; i++) {
		table[i] = (Node*)malloc(sizeof(Node) * col);
		table[i][0].data = arr[i][0];

		table[i][0].seq = (int*)malloc(sizeof(int));
		table[i][0].seq[0] = arr[i][0];

	}

	for (i = 1; i < col; i++) {
		for (j = 0; j < row; j++) {
			int preIdx = FindMinIDX(table, j, i, row);

			table[j][i].data = table[preIdx][i - 1].data + arr[j][i];

			table[j][i].seq = (int*)malloc(sizeof(int) * (i + 1));
			for (int t = 0; t < i; t++) {
				table[j][i].seq[t] = table[preIdx][i - 1].seq[t];
			}
			table[j][i].seq[i] = arr[j][i];

		}
	}

	int min = table[0][col - 1].data;
	int minIdx = 0;

	for (i = 1; i < row; i++) {
		if (min > table[i][col - 1].data) {
			min = table[i][col - 1].data;
			minIdx = i;
		}
	}

	for (i = 0; i < col; i++)
		printf("%d ", table[minIdx][col - 1].seq[i]);
	printf("\n");
	printf("%d\n", table[minIdx][col - 1].data);

	free(table);
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
		FindCheapWay(arr, n, m);
	}
	
	fclose(fp);

	return 0;
}
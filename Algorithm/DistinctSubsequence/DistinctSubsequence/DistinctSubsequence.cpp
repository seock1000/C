#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InputString(char str[], char compStr[], FILE* fp) {
	fscanf(fp, "%s", str);
	fscanf(fp, "%s", compStr);
}

int DistinctSubseq(char str[], char compStr[], int len, int compLen) {
	int** table = (int**)malloc(sizeof(int*) * compLen);
	for (int row = 0; row < compLen; row++)
		table[row] = (int*)malloc(sizeof(int) * len);

	int i, j;
	int rdata;

	if (str[0] == compStr[0])
		table[0][0] = 1;
	else
		table[0][0] = 0;

	for (i = 1; i < compLen; i++)
		table[i][0] = 0;

	for (i = 1; i < len; i++) {
		table[0][i] = table[0][i - 1];
		if (compStr[0] == str[i])
			table[0][i]++;
			
	}

	for (i = 1; i < compLen; i++) {
		for (j = 1; j < len; j++) {
			table[i][j] = table[i][j - 1];
			if (compStr[i] == str[j])
				table[i][j] += table[i - 1][j - 1];
		}
	}
	
	rdata = table[compLen - 1][len - 1];
	free(table);

	return rdata;
}

int main() {
	FILE* fp;

	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("file open fail!\n");
		exit(-1);
	}

	int n;

	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		char str[10001];
		char compStr[101];

		InputString(str, compStr, fp);
		printf("%d\n", DistinctSubseq(str, compStr, strlen(str), strlen(compStr)));
	}

	fclose(fp);

	return 0;
}
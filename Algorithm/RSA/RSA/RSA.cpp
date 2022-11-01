#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void FindPQ(int n, int* p, int* q) {
	int i, j;
	for (i = 2; i < n; i++) {
		int cnt = 0;
		for (j = 2; j < i; j++) {
			if (i % j == 0)
				cnt++;
		}

		if (cnt == 0 && n % i == 0) {
			*p = i;
			*q = n / i;
			return;
		}
	}
}

int FindD(int t, int e) {
	int i = 1;
	while (i < t) {
		if ((i * t + 1) % e == 0)
			return (i * t + 1) / e;
		i++;
	}
	printf("Can't find D\n");
	exit(-1);
}

int binary(int k, int arr[])
{
	int i = 0;
	int value = k;
	while (1)
	{
		arr[i] = value % 2;
		value = value / 2;
		if (value == 0)
			break;
		i++;
	}
	return i;
}

int Decrypt_message(int a, int b, int n) {
	int arr[1000];
	int index, c = 0, d = 1;
	index = binary(b, arr);
	for (int i = index; i >= 0; i--) {
		c = 2 * c;
		d = (d * d) % n;
		if (arr[i] == 1) {
			c = c + 1;
			d = (d * a) % n;
		}
	}
	return d;
}

int RSA(int n, int e, int message) {
	int t, p, q, d;
	FindPQ(n, &p, &q);
	t = (p - 1) * (q - 1);
	d = FindD(t, e);

	while (d < 0) {
		d = d + t;
	}
	return Decrypt_message(message, d, n);
}

int main(void) {
	int n, e, message;
	FILE* fp;
	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		puts("File open fail!\n");
		exit(0);
	}
	while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &e, &n, &message);
		printf("Decoded message : %d\n", RSA(n, e, message));
	}
	fclose(fp);
}


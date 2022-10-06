#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** recursive factorial
int factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int main() {
	int n;
	printf("Enter n : ");
	scanf("%d", &n);

	printf("%d! = %d\n", n, factorial(n));

	return 0;
}
*/

/** fibonacci 
int fibo(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int n;
	printf("Enter n : ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Wrong Input!\n");
		exit(-1);
	}

	printf("%dth number : %d\n", n, fibo(n));

	return 0;
}
*/

/** hong gil dong 

int IsMatch(char* compstr, char* str) {
	int compLen = strlen(compstr);
	int len = strlen(str);
	int i, j;

	for (i = 0; i < compLen - len; i++) {
		int t = 0;
		for (j = i; j < i + len; j++) {
			if (compstr[j] != str[t])
				break;
			t++;
		}
		if (t == len)
			return 1;
	}
	return 0;
}

int main() {
	char compstr[100];
	char str[20];

	printf("Enter string : ");
	gets_s(compstr, 100);
	printf("Enter the word to find : ");
	gets_s(str, 20);

	if (IsMatch(compstr, str))
		printf("Match\n");

	else
		printf("Not match\n");

	return 0;
}
*/

/*
// iterative factorial
int factorial(int n) {
	int fac = 1;
	if (n < 0) {
		printf("Wrong Input!\n");
		exit(-1);
	}

	else if (n == 0)
		return 0;

	for (int i = 1; i <= n; i++) {
		fac *= i;
	}

	return fac;
}

int main() {
	int n;
	printf("Enter n : ");
	scanf("%d", &n);

	printf("%d! = %d\n", n, factorial(n));

	return 0;
}
*/

/*
// recursive sum
int sum_of(int a[], int n) {
	if (n == 0)
		return a[n];

	return a[n] + sum_of(a, n - 1);
}

int main() {
	int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int n;

	printf("Enter n : ");
	scanf("%d", &n);

	printf("sum : %d", sum_of(arr, n));

	return 0;
}
*/

/*
// iterative sum 
int sum_of(int a[], int n) {
	int sum = 0;

	for (int i = 0; i <= n; i++)
		sum += a[i];

	return sum;
}

int main() {
	int arr[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int n;

	printf("Enter n : ");
	scanf("%d", &n);

	printf("sum : %d", sum_of(arr, n));

	return 0;
}
*/

/*
// recursive power
double pow(float n, int power) {
	if (power == 0)
		return 1;

	return n * pow(n, power - 1);
}

int main() {
	int n;
	float power;

	printf("Enter values : ");
	scanf("%d %f", &n, &power);

	printf("%.lf", pow(n, power));

	return 0;
}
*/

/*
// iterative power
double pow(float n, int power) {
	double result = 1;

	for (int i = 0; i < power; i++) {
		result *= n;
	}

	return result;
}

int main() {
	int n;
	float power;

	printf("Enter values : ");
	scanf("%d %f", &n, &power);

	printf("%.lf", pow(n, power));

	return 0;
}
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i;
	FILE* fp; // file pointer fp ����
	double price[2] = { 139.25, 19.03 }; // double�� �迭 price ���� �� ������ ����
	const char* description[2] = { "glove", "CD" }; // ���ڿ� �迭 description ���� �� ������ ����

	fp = fopen("price.txt", "w"); // write ���� price.txt file ��Ʈ�� ����
	if (fp == NULL) // ���� ��Ʈ���� ����� �������� �ʾҴٸ� ���� �޼���
		printf("\nFile Could Not Be Opened");
	else {
		for (i = 0; i < 2; i++)
			fprintf(fp, "%-9s %6.2f\n", description[i], price[i]); // �迭�� ����� ������ file�� print
		fclose(fp); // ���� ��Ʈ�� close
	}
	return 0;
}
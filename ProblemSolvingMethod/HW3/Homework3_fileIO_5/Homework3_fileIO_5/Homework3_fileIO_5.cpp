#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	FILE *fp; // file pointer ���� ����
	char ch;

	fp = fopen("data.txt", "r"); // read ���� ���� ��Ʈ�� ����
	if (fp == NULL) { // ���� ��Ʈ���� ����� �������� �ʾҴٸ� �����޼��� ���
		printf("Could not open data.txt!\n"); 
	}

	while ((ch = fgetc(fp)) != EOF) // fgetc�� data.txt ���Ϸ� ���� ���� 1���� �о���� �ش� ���ڰ� End Of File�� �ƴҵ���
		putchar(ch); // ch�� �ֿܼ� ���

	fclose(fp); // ��� �Ϸ��� ���� ��Ʈ�� close

	return 0;
}
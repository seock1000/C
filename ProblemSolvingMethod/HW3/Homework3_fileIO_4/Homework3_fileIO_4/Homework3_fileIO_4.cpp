#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i;
	FILE* fp; // file pointer ����
	fp = fopen("myinFile.txt", "r"); // read ���� ���� ��Ʈ�� ����

	if (fp == NULL) // ���� ��Ʈ���� ����� �������� �ʾҴٸ� �����޼��� ���
		printf("\nFile Could Not Be Opened");
	else {
		char ch = fgetc(fp); // fgetc�� ���Ϸκ��� 1���� ���� read
		while (ch != EOF) { // ch�� End Of File�� �ƴҵ���
			putchar(ch); // ch�� �ֿܼ� ���
			ch = fgetc(fp); // fgetc�� ���Ϸκ��� 1���� ���� read
		}
		printf("\nFinished printing the file\n");
		fclose(fp); // ��� �Ϸ��� ���Ͻ�Ʈ�� close
	}
}
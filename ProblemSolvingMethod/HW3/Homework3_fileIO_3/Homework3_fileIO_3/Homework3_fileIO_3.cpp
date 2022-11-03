#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* infile; // file pointer ����
	char line[100]; // ���ڿ� ���� char �迭 ����
	int lcount = 0; 

	if ((infile = fopen("charstream.txt", "r")) == NULL) { // read ���� ���� ��Ʈ�� ���� �� ����� �������� �ʾҴٸ� �����޼��� ���
		printf("File Could Not Be Opened.\n");
	}

	while (fgets(line, sizeof(line), infile) != NULL) { // charstream.txt ���Ͽ��� ���ڿ� read, fgets�� NULL�� ��ȯ�Ҷ����� �ݺ�
		lcount++;
		printf("Line %d : %s", lcount, line); // ���� ���ڿ� ���
	}

	fclose(infile); // ��� �Ϸ��� ��Ʈ�� close

	return 0;
}
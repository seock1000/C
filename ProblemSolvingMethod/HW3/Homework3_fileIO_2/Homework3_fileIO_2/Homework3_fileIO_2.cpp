#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, sum = 0;
	FILE* infile; // input ���� file pointer ����
	FILE* outfile; // output ���� file pointer ����

	infile = fopen("myinFile.txt", "r"); // input file stream ����
	if (infile == NULL) { // ����� �������� �ʾ����� �����޼��� ���
		printf("Input File Could Not Be Opened.");
	}

	outfile = fopen("myoutFile.txt", "w"); // output file stream ����
	if (outfile == NULL) { // ����� �������� �ʾ����� �����޼��� ���
		printf("Output File Could Not Be Opened.");
	}

	while (fscanf(infile, "%d", &a) != EOF) // fscaf�� End Of File�� �����Ҷ�����
		sum += a; // myinFile.txt���� �о�� �����͸� ���ϱ�
	fprintf(outfile, "The sum is %d\n", sum); // sum ���� outfile ��Ʈ���� ���� myoutFile.txt�� print

	fclose(infile);
	fclose(outfile); // ��� �Ϸ��� ���� ��Ʈ���� close

	return 0;
}
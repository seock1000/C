#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE *infile, *outfile; // input file pointer ����, output file pointer ���� ����
	char ch;

	infile = fopen("data.txt", "r"); // read ���� ���� ��Ʈ�� ����
	if (infile == NULL) { // ���� ��Ʈ���� ����� �������� �ʾҴٸ� �����޼��� ���
		printf("Could not open data.txt!\n");
	}

	outfile = fopen("samedata.txt", "w"); // write ���� ���� ��Ʈ�� ����
	if (outfile == NULL) { // ���� ��Ʈ���� ����� �������� �ʾҴٸ� �����޼��� ���
		printf("Could not open samedata.txt!\n");
	}

	while ((ch = fgetc(infile)) != EOF) // fgetc�� data.txt�κ��� ���� 1���� �о���� �ش� ���ڰ� EOF�� �ƴѵ��� �ݺ�
		fputc(ch, outfile); // samedata.txt�� ch print

	fclose(infile);
	fclose(outfile); // ��� �Ϸ��� ���� ��Ʈ�� close

	return 0;
}
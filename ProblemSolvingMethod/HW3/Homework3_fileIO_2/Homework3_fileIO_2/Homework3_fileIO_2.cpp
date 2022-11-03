#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, sum = 0;
	FILE* infile; // input 받을 file pointer 선언
	FILE* outfile; // output 받을 file pointer 선언

	infile = fopen("myinFile.txt", "r"); // input file stream 생성
	if (infile == NULL) { // 제대로 생성되지 않았으면 에러메세지 출력
		printf("Input File Could Not Be Opened.");
	}

	outfile = fopen("myoutFile.txt", "w"); // output file stream 생성
	if (outfile == NULL) { // 제대로 생성되지 않았으면 에러메세지 출력
		printf("Output File Could Not Be Opened.");
	}

	while (fscanf(infile, "%d", &a) != EOF) // fscaf가 End Of File을 반한할때까지
		sum += a; // myinFile.txt에서 읽어온 데이터를 더하기
	fprintf(outfile, "The sum is %d\n", sum); // sum 값을 outfile 스트림을 통해 myoutFile.txt에 print

	fclose(infile);
	fclose(outfile); // 사용 완료한 파일 스트림을 close

	return 0;
}
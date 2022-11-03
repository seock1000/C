#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	FILE *infile, *outfile; // input file pointer 변수, output file pointer 변수 선언
	char ch;

	infile = fopen("data.txt", "r"); // read 모드로 파일 스트림 생성
	if (infile == NULL) { // 파일 스트림이 제대로 생성되지 않았다면 에러메세지 출력
		printf("Could not open data.txt!\n");
	}

	outfile = fopen("samedata.txt", "w"); // write 모드로 파일 스트림 생성
	if (outfile == NULL) { // 파일 스트림이 제대로 생성되지 않았다면 에러메세지 출력
		printf("Could not open samedata.txt!\n");
	}

	while ((ch = fgetc(infile)) != EOF) // fgetc로 data.txt로부터 문자 1개를 읽어오고 해당 문자가 EOF가 아닌동안 반복
		fputc(ch, outfile); // samedata.txt에 ch print

	fclose(infile);
	fclose(outfile); // 사용 완료한 파일 스트림 close

	return 0;
}
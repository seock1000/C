#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* infile; // file pointer 선언
	char line[100]; // 문자열 저장 char 배열 선언
	int lcount = 0; 

	if ((infile = fopen("charstream.txt", "r")) == NULL) { // read 모드로 파일 스트림 생성 후 제대로 생성되지 않았다면 에러메세지 출력
		printf("File Could Not Be Opened.\n");
	}

	while (fgets(line, sizeof(line), infile) != NULL) { // charstream.txt 파일에서 문자열 read, fgets가 NULL을 반환할때까지 반복
		lcount++;
		printf("Line %d : %s", lcount, line); // 읽은 문자열 출력
	}

	fclose(infile); // 사용 완료한 스트림 close

	return 0;
}
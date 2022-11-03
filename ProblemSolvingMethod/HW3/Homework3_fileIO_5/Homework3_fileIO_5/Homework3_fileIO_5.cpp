#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	FILE *fp; // file pointer 변수 선언
	char ch;

	fp = fopen("data.txt", "r"); // read 모드로 파일 스트림 생성
	if (fp == NULL) { // 파일 스트림이 제대로 생성되지 않았다면 에러메세지 출력
		printf("Could not open data.txt!\n"); 
	}

	while ((ch = fgetc(fp)) != EOF) // fgetc로 data.txt 파일로 부터 문자 1개를 읽어오고 해당 문자가 End Of File이 아닐동안
		putchar(ch); // ch를 콘솔에 출력

	fclose(fp); // 사용 완료한 파일 스트림 close

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i;
	FILE* fp; // file pointer 선언
	fp = fopen("myinFile.txt", "r"); // read 모드로 파일 스트림 생성

	if (fp == NULL) // 파일 스트림이 제대로 생성되지 않았다면 에러메세지 출력
		printf("\nFile Could Not Be Opened");
	else {
		char ch = fgetc(fp); // fgetc로 파일로부터 1개의 문자 read
		while (ch != EOF) { // ch가 End Of File이 아닐동안
			putchar(ch); // ch를 콘솔에 출력
			ch = fgetc(fp); // fgetc로 파일로부터 1개의 문자 read
		}
		printf("\nFinished printing the file\n");
		fclose(fp); // 사용 완료한 파일스트림 close
	}
}
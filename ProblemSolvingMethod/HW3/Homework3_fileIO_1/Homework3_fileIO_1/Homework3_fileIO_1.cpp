#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i;
	FILE* fp; // file pointer fp 선언
	double price[2] = { 139.25, 19.03 }; // double형 배열 price 선언 및 데이터 삽입
	const char* description[2] = { "glove", "CD" }; // 문자열 배열 description 선언 및 데이터 삽입

	fp = fopen("price.txt", "w"); // write 모드로 price.txt file 스트림 생성
	if (fp == NULL) // 파일 스트림이 제대로 생성되지 않았다면 에러 메세지
		printf("\nFile Could Not Be Opened");
	else {
		for (i = 0; i < 2; i++)
			fprintf(fp, "%-9s %6.2f\n", description[i], price[i]); // 배열에 저장된 데이터 file에 print
		fclose(fp); // 파일 스트림 close
	}
	return 0;
}
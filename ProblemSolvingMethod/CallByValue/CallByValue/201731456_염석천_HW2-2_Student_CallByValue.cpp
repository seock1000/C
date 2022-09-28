#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NAME_LEN 64
#define NUM 2

// 구조체 정의
struct student {
	char name[20];
	int height;
	float weight;
	int schols;
};

// call by value, 값을 통한 호출
struct student func(struct student stu) {
	// 구조체를 받아와서 조건에 맞게 수정한 뒤
	if (stu.height < 180) stu.height = 180;
	if (stu.weight < 100) stu.weight = 100; 
	// 수정한 구조체를 리턴
	return stu;
}

int main() {
	struct student stu[NUM]; // 구조체 배열 선언
	
	// 구조체 배열의 요소에 값 입력
	for (int i = 0; i < NUM; i++) {
		printf("Type %d-th student's into (Name, height, weight, schols) : ", i);
		scanf("%s %d %f %d", &stu[i].name, &stu[i].height, &stu[i].weight, &stu[i].schols);
	}

	// 조건에 맞게 구조체 멤버의 값 수정
	for (int i = 0; i < NUM; i++) {
		// 임시로 값을 저장할 구조체 변수 tmp 선언하여, 조건에 맞게 수정된 구조체 저장
		struct student tmp = func(stu[i]); 
		// 수정된 구조체를 stu[i]에 저장
		stu[i] = tmp;
	}

	// 결과 출력
	for (int i = 0; i < NUM; i++) {
		printf("Name    = %10s\n", stu[i].name);
		printf("Height  = %10d\n", stu[i].height);
		printf("Weight  = %10f\n", stu[i].weight);
		printf("Schols  = %10d\n\n", stu[i].schols);
	}

	return 0;
}
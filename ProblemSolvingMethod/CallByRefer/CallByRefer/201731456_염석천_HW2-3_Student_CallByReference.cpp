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

// call by reference, 참조를 통한 호출
// 파라미터로 구조체 포인터 변수로 받음
// 즉, 주소 값을 이용하므로 인자로 받은 주소에 저장된 값을 함수 내에서 변경 가능
void func(struct student* stu) {
	// 조건에 맞게 변경, stu->height == (*stu).height
	if (stu->height < 180) stu->height = 180;
	if (stu->weight < 100) stu->weight = 100;
	// 주소값에 저장된 값을 변경하므로 반환 값은 필요없음
}

int main() {
	struct student stu[NUM]; // 구조체 배열 선언

	// 구조체 배열의 요소에 값 입력
	for (int i = 0; i < NUM; i++) {
		printf("Type %d-th student's into (Name, height, weight, schols) : ", i);
		scanf("%s %d %f %d", &stu[i].name, &stu[i].height, &stu[i].weight, &stu[i].schols);
	}

	// 조건에 맞게 구조체 멤버의 값 수정
	for (int i = 0; i < NUM; i++)
		func(&stu[i]); // 구조체 배열의 각 요소의 주소값 전달

	// 결과 출력
	for (int i = 0; i < NUM; i++) {
		printf("Name    = %10s\n", stu[i].name);
		printf("Height  = %10d\n", stu[i].height);
		printf("Weight  = %10f\n", stu[i].weight);
		printf("Schols  = %10d\n\n", stu[i].schols);
	}

	return 0;
}
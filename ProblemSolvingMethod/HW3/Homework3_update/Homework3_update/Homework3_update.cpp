#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>

struct EMP { // EMP 구조체 정의
	int RRN;
	char name[20];
	float salary; 
	float bonus;
}; 

// 이전에 입력된 데이터 중 새로 입력된 데이터와 같은 RRN이 존재하는지 확인
// input : EMP 배열, 새로 입력된 데이터, 배열에 저장된 데이터의 수
// output : 같은 데이터가 존재하면 1 반환, 그렇지 않다면 0 반환
int check_prev(struct EMP* arr, struct EMP emp, int count) {
	for (int i = 0; i < count; i++) {
		if (arr[i].RRN == emp.RRN)
			return 1;
	}
	return 0;
}

int main() {
	struct EMP employee[MAX]; // MAX 길이로 EMP 구조체 배열 선언
	int total_num = 0; // 입력받을 데이터의 개수 저장 변수
	int register_num = 0; // 저장된 데이터의 개수 저장 변수
	printf("Type the number of employees : ");
	scanf("%d", &total_num);

	// total_num만큼 반복
	for (int i = 0; i < total_num; i++) {
		struct EMP tmp; // constraint 검사하기 전 임시 저장용 EMP 구조체 변수 선언
		printf("\nType employee information(RRN, name, salary, bonus) : ");
		scanf("%d %s %f %f", &tmp.RRN, &tmp.name, &tmp.salary, &tmp.bonus); // 데이터 입력

		// check_prev 함수 호출, RRN이 같은 데이터가 있으면 에러
		if (check_prev(employee, tmp, register_num)) {
			printf("Error : the RRN is already registered!\n\n");
		}
		// bonus가 salary 보다 크거나 같다면 에러
		else if (tmp.bonus >= tmp.salary) {
			printf("Error : the bonus must be less than salary!\n\n");
		}
		// 제약조건에 걸리지 않는다면 입력받은 데이터를 array에 저장
		else {
			printf("The employee has been registered!\n\n");
			employee[register_num] = tmp;
			register_num++; // array에 저장된 데이터의 개수 1 증가
		}
	}

	// array에 저장된 데이터 출력
	for (int i = 0; i < register_num; i++) {
		printf("%d-th employee: RRN=%d Name=%s Salary=%f Bonus=%f\n", i, employee[i].RRN, employee[i].name, employee[i].salary, employee[i].bonus);
	}
	
	return 0;
}


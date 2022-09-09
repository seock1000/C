#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// find and store index of max value in the array
// input : array, array length and array for store max index
// output : the number of max index
int FindMaxValueIdx(int arr[], int idxArr[], int n) {
	int i;
	int maxCnt = 1; // max값의 개수를 카운트하는 변수
	int max = arr[0]; // max값 저장을 위한 변수, 배열의 첫 번째 요소로 초기화
	idxArr[0] = 0; // max값의 index를 저장하는 배열, max값을 arr[0]으로 초기화 했기 때문에 0으로 초기화

	for (i = 1; i < n; i++) {
		if (max < arr[i]) { // 새로운 max값을 찾았을 때
			max = arr[i]; // max값을 변경하고
			idxArr[0] = i; // 해당 index를 index 저장 배열의 첫번째 요소에 저장
			maxCnt = 1; // 첫 번째 max값이므로 max값의 개수 1로 설정
		}
		else if (max == arr[i]) { // max값과 동일할 때
			idxArr[maxCnt] = i; // index 저장 배열에 이어서 저장
			maxCnt++; // max값의 개수를 증가
		}
	}

	return maxCnt; // 모든 과정 종료 후 총 max값의 개수 반환
}

// find and store index of min value in the array
// input : array, array length and array for store min index
// output : the number of min index
int FindMinValueIdx(int arr[], int idxArr[], int n) {
	int i;
	int minCnt = 1; // min값의 개수를 카운트하는 변수
	int min = arr[0]; // min값 저장을 위한 변수, 배열의 첫 번째 요소로 초기화
	idxArr[0] = 0; // min값의 index를 저장하는 배열, min값을 arr[0]으로 초기화 했기 때문에 0으로 초기화

	for (i = 1; i < n; i++) {
		if (min > arr[i]) { // 새로운 min값을 찾았을 때
			min = arr[i]; // min값을 변경하고
			idxArr[0] = i; // 해당 index를 index 저장 배열의 첫번째 요소에 저장
			minCnt = 1; // 첫 번째 min값이므로 min값의 개수 1로 설정
		}
		else if (min == arr[i]) { // min값과 동일할 때
			idxArr[minCnt] = i; // index 저장 배열에 이어서 저장
			minCnt++; // min값의 개수를 증가
		}
	}

	return minCnt; // 모든 과정 종료 후 총 min값의 개수 반환
}

int main() {
	int age[100]; // age의 저장을 위한 배열 선언
	int score[100]; // score의 저정을 위한 배열 선언
	int cnt = 0, i; // 총 입력된 데이터의 수를 카운트하는 변수 cnt 선언 0으로 초기화
	int idx[100]; // index의 저장을 위한 배열 선언

	for (i = 0; i < 100; i++) { // 100번 입력 반복
		printf("Put age and score pair (End : -1 -1) : ");
		scanf("%d %d", &age[i], &score[i]);
		if (age[i] == -1 && score[i] == -1) // -1 -1이 입력되면 입력 종료
			break;
		cnt++; // 입력된 데이터의 수 카운트
	}

	if (cnt == 0) { // 입력된 데이터가 없으면 종료
		printf("Data not exist.\n");
		exit(-1);
	}

	for (i = 0; i < FindMaxValueIdx(age, idx, cnt); i++) { // age 배열의 max값 개수만큼 반복
		printf("Oldest age(%d) score as %d\n", age[idx[i]], score[idx[i]]); // age 배열의 max값 index에 해당하는 score 배열의 값 출력
	}

	for (i = 0; i < FindMinValueIdx(age, idx, cnt); i++) { // age 배열의 min값 개수만큼 반복
		printf("Youngest age(%d) score as %d\n", age[idx[i]], score[idx[i]]); // age 배열의 min값 index에 해당하는 score 배열의 값 출력
	}

	for (i = 0; i < FindMaxValueIdx(score, idx, cnt); i++) { // score 배열의 max값 개수만큼 반복
		printf("Max score(%d) age as %d\n", score[idx[i]], age[idx[i]]); // score 배열의 max값 index에 해당하는 age 배열의 값 출력
	}

	for (i = 0; i < FindMinValueIdx(score, idx, cnt); i++) { // score 배열의 min값 개수만큼 반복
		printf("Min score(%d), age as %d\n", score[idx[i]], age[idx[i]]); // score 배열의 min값 index에 해당하는 age 배열의 값 출력
	}

	return 0;
}
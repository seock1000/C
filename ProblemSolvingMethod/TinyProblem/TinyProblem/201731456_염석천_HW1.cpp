#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// find and store index of max value in the array
// input : array, array length and array for store max index
// output : the number of max index
int FindMaxValueIdx(int arr[], int idxArr[], int n) {
	int i;
	int maxCnt = 1; // max���� ������ ī��Ʈ�ϴ� ����
	int max = arr[0]; // max�� ������ ���� ����, �迭�� ù ��° ��ҷ� �ʱ�ȭ
	idxArr[0] = 0; // max���� index�� �����ϴ� �迭, max���� arr[0]���� �ʱ�ȭ �߱� ������ 0���� �ʱ�ȭ

	for (i = 1; i < n; i++) {
		if (max < arr[i]) { // ���ο� max���� ã���� ��
			max = arr[i]; // max���� �����ϰ�
			idxArr[0] = i; // �ش� index�� index ���� �迭�� ù��° ��ҿ� ����
			maxCnt = 1; // ù ��° max���̹Ƿ� max���� ���� 1�� ����
		}
		else if (max == arr[i]) { // max���� ������ ��
			idxArr[maxCnt] = i; // index ���� �迭�� �̾ ����
			maxCnt++; // max���� ������ ����
		}
	}

	return maxCnt; // ��� ���� ���� �� �� max���� ���� ��ȯ
}

// find and store index of min value in the array
// input : array, array length and array for store min index
// output : the number of min index
int FindMinValueIdx(int arr[], int idxArr[], int n) {
	int i;
	int minCnt = 1; // min���� ������ ī��Ʈ�ϴ� ����
	int min = arr[0]; // min�� ������ ���� ����, �迭�� ù ��° ��ҷ� �ʱ�ȭ
	idxArr[0] = 0; // min���� index�� �����ϴ� �迭, min���� arr[0]���� �ʱ�ȭ �߱� ������ 0���� �ʱ�ȭ

	for (i = 1; i < n; i++) {
		if (min > arr[i]) { // ���ο� min���� ã���� ��
			min = arr[i]; // min���� �����ϰ�
			idxArr[0] = i; // �ش� index�� index ���� �迭�� ù��° ��ҿ� ����
			minCnt = 1; // ù ��° min���̹Ƿ� min���� ���� 1�� ����
		}
		else if (min == arr[i]) { // min���� ������ ��
			idxArr[minCnt] = i; // index ���� �迭�� �̾ ����
			minCnt++; // min���� ������ ����
		}
	}

	return minCnt; // ��� ���� ���� �� �� min���� ���� ��ȯ
}

int main() {
	int age[100]; // age�� ������ ���� �迭 ����
	int score[100]; // score�� ������ ���� �迭 ����
	int cnt = 0, i; // �� �Էµ� �������� ���� ī��Ʈ�ϴ� ���� cnt ���� 0���� �ʱ�ȭ
	int idx[100]; // index�� ������ ���� �迭 ����

	for (i = 0; i < 100; i++) { // 100�� �Է� �ݺ�
		printf("Put age and score pair (End : -1 -1) : ");
		scanf("%d %d", &age[i], &score[i]);
		if (age[i] == -1 && score[i] == -1) // -1 -1�� �ԷµǸ� �Է� ����
			break;
		cnt++; // �Էµ� �������� �� ī��Ʈ
	}

	if (cnt == 0) { // �Էµ� �����Ͱ� ������ ����
		printf("Data not exist.\n");
		exit(-1);
	}

	for (i = 0; i < FindMaxValueIdx(age, idx, cnt); i++) { // age �迭�� max�� ������ŭ �ݺ�
		printf("Oldest age(%d) score as %d\n", age[idx[i]], score[idx[i]]); // age �迭�� max�� index�� �ش��ϴ� score �迭�� �� ���
	}

	for (i = 0; i < FindMinValueIdx(age, idx, cnt); i++) { // age �迭�� min�� ������ŭ �ݺ�
		printf("Youngest age(%d) score as %d\n", age[idx[i]], score[idx[i]]); // age �迭�� min�� index�� �ش��ϴ� score �迭�� �� ���
	}

	for (i = 0; i < FindMaxValueIdx(score, idx, cnt); i++) { // score �迭�� max�� ������ŭ �ݺ�
		printf("Max score(%d) age as %d\n", score[idx[i]], age[idx[i]]); // score �迭�� max�� index�� �ش��ϴ� age �迭�� �� ���
	}

	for (i = 0; i < FindMinValueIdx(score, idx, cnt); i++) { // score �迭�� min�� ������ŭ �ݺ�
		printf("Min score(%d), age as %d\n", score[idx[i]], age[idx[i]]); // score �迭�� min�� index�� �ش��ϴ� age �迭�� �� ���
	}

	return 0;
}
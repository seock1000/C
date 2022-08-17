#include "SimpleHeap.h"

// initialize heap
// input : pointer of heap
// output : void
void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

// check if heap is empty or not
// input : pointer of heap
// output : true if heap is empty, false if heap isn't empty
int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

// return parent's index
// current index
// parent's index
int GetParentIDX(int idx) {
	return idx / 2;
}

// return left child's index
// current index
// left child's index
int GetLChildIDX(int idx) {
	return idx * 2;
}

// return right child's index
// current index
// right child's index
int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

// return child's index that has higher priority between left and right child
// pointer of heap and current index
// child's index that has higher priority
int GetHiPriChildIDX(Heap* ph, int idx) {

	if (GetLChildIDX(idx) > ph->numOfData) // child�� ������
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // left child�� ������
		return GetLChildIDX(idx);
	else { // left, right child�� �� �� ������
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) // right child�� �켱������ ������
			return GetRChildIDX(idx);
		else // left child�� �켱������ ������
			return GetLChildIDX(idx);
	}
}

// insert data into heap
// input : pointer of heap, data to insert and informaition of priority
// output : void
void HInsert(Heap* ph, HData data, Priority pr) {

	int idx = ph->numOfData + 1; // Ʈ���� ������ ��ġ
	HeapElem nelem = { pr, data }; // ��� ����

	while(idx != 1) { // ��Ʈ ����� ��ġ����
		if (pr < ph->heapArr[GetParentIDX(idx)].pr) { // ���� �߰��Ǵ� ��尡 �θ��庸�� �켱������ ������
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx); // �θ���� ��ġ ����
		}
		else // �θ��庸�� �켱������ ������ �ߴ�
			break;
	}
	ph->heapArr[idx] = nelem; // �������� ���� index�� ��� ����
	ph->numOfData += 1;
}

// delete root node and return data of deleted node
// input : pointer of heap
// output : Data of deleted node
HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1].data; // ������ ���(��Ʈ ���)�� ������ �ӽ� ����
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // Ʈ���� ������ ��ġ�� ��带 ��Ʈ����

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) { // childIdx�� �켱 ������ ���� child�� index ����, child�� ���� ������ �ݺ�
		if (lastElem.pr <= ph->heapArr[childIdx].pr) // �°ݵ� ����� �켱������ child ���� ���ų� ������ �ߴ�
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // �׷��� ������, child�� ��ġ�� ����
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem; // ���� index�� ������ ��ġ�� ��� ����
	ph->numOfData -= 1;
	return retData;
}
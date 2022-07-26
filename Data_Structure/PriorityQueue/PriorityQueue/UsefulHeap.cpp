#include "UsefulHeap.h"

// initialize heap
// input : pointer of heap
// output : void
void HeapInit(Heap* ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc;
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
// input : current index
// output : parent's index
int GetParentIDX(int idx) {
	return idx / 2;
}

// return left child's index
// input : current index
// output : left child's index
int GetLChildIDX(int idx) {
	return idx * 2;
}

// return right child's index
// input : current index
// output : right child's index
int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

// return child's index that has higher priority between left and right child
// input : pointer of heap and current index
// output : child's index that has higher priority
int GetHiPriChildIDX(Heap* ph, int idx) {

	if (GetLChildIDX(idx) > ph->numOfData) // child가 없으면
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData) // left child만 있으면
		return GetLChildIDX(idx);
	else { // left, right child가 둘 다 있으면
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0) // right child의 우선순위가 높으면
			return GetRChildIDX(idx);
		else // left child의 우선순위가 높으면
			return GetLChildIDX(idx);
	}
}

// insert data into heap
// input : pointer of heap, data to insert and informaition of priority
// output : void
void HInsert(Heap* ph, HData data) {

	int idx = ph->numOfData + 1; // 트리의 마지막 위치

	while (idx != 1) { // 루트 노드의 위치까지
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) { // 새로 추가되는 노드가 부모노드보다 우선순위가 높으면
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx); // 부모노드와 위치 변경
		}
		else // 부모노드보다 우선순위가 낮으면 중단
			break;
	}
	ph->heapArr[idx] = data; // 최종으로 나온 index에 노드 저장
	ph->numOfData += 1;
}

// delete root node and return data of deleted node
// input : pointer of heap
// output : Data of deleted node
HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1]; // 삭제할 노드(루트 노드)의 데이터 임시 저장
	HData lastData = ph->heapArr[ph->numOfData]; // 트리의 마지막 위치의 노드를 루트노드로

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) { // childIdx에 우선 순위가 높은 child의 index 저장, child가 없을 때까지 반복
		if (ph->comp(lastData, ph->heapArr[childIdx]) > 0) // 승격된 노드의 우선순위가 child 보다 높거나 같으면 중단
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // 그렇지 않으면, child와 위치를 변경
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastData; // 최종 index에 마지막 위치의 노드 저장
	ph->numOfData -= 1;
	return retData;
}
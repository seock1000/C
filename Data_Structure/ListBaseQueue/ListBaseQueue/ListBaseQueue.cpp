#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

// initialize queue
// input : pointer of queue
// output : void
void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL; // 초기상태 : front와 rear가 NULL
}

// check if queue is empty or not
// input : pointer of queue
// output : TRUE(1) if queue is empty, FALSE(0) if queue isn't empty
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL) // front가 NULL을 가리키면
		return TRUE;
	else
		return FALSE;
}

// insert a data to the queue
// input : pointer of queue and data to insert 
// output : void
void Enqueue(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 노드 생성
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) { // 첫 번째 노드의 추가인 경우,
		pq->front = newNode;
		pq->rear = newNode; // front와 rear가 모두 새 노드를 가리키게
	}
	else { // 두 번째 이후의 노드의 추가인 경우,
		pq->rear->next = newNode;
		pq->rear = newNode; // 리스트의 꼬리에 새 노드 추가하고 front는 그대로, rear가 새 노드를 가리키게
	}
}

// delete first data and return the deleted data
// input : pointer of queue
// output : deleted data
Data Dequeue(Queue* pq) {
	Node* delNode; 
	Data retData; 

	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	delNode = pq->front; // 삭제할 노드의 주소값 임시 저장
	retData = pq->front->data; // 삭제할 노드의 데이터 임시 저장
	pq->front = pq->front->next; // front가 다음 노드를 가리키게

	free(delNode); // 노드 삭제

	return retData;
}

// return the first data without deletion
// input : pointer of queue
// output : first data
Data QPeek(Queue* pq) {
	
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	return pq->front->data;
}
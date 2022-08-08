#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// Initialize Queue
// input : pointer of the queue
// output : void
void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}

// Check if queue is empty or not
// input : pointer of the queue
// output : TRUE if queue is empty, FALSE if queue isn't empty
int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear) // front와 rear가 동일한 위치를 가리키면
		return TRUE;
	else
		return FALSE;
}

// return next index on circular queue
// input : current position on circular queue
// output : next position on the queue 
int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1) // 전달받은 값이 배열의 마지막 주소이면
		return 0;
	else
		return pos + 1;
}

// insert data to the queue
// input : pointer of the queue and data to insert
// output : void
void Enqueue(Queue* pq, Data data) {
	// rear의 다음 위치가 front의 현위치와 같으면(Queue가 full이면)
	if (NextPosIdx(pq->rear) == pq->front) { 
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear); // rear를 앞으로 한 칸 이동
	pq->queArr[pq->rear] = data;
}

// delete first data of queue and return deleted data
// input : pointer of queue
// output : deleted data at the queue
Data Dequeue(Queue* pq) {

	if (QIsEmpty(pq)) { // queue가 empty면
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front); // front를 앞으로 한 칸 이동

	return pq->queArr[pq->front];
}

// return the first data of queue with no deletion
// input : pointer of queue
// output : the first data of queue
Data QPeek(Queue* pq) {

	if (QIsEmpty(pq)) { // queue가 empty면
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)]; // front를 앞으로 한 칸 이동시킨 위치의 데이터 반환
}
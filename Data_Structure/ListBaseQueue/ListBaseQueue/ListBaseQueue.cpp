#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

// initialize queue
// input : pointer of queue
// output : void
void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL; // �ʱ���� : front�� rear�� NULL
}

// check if queue is empty or not
// input : pointer of queue
// output : TRUE(1) if queue is empty, FALSE(0) if queue isn't empty
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL) // front�� NULL�� ����Ű��
		return TRUE;
	else
		return FALSE;
}

// insert a data to the queue
// input : pointer of queue and data to insert 
// output : void
void Enqueue(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // ��� ����
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) { // ù ��° ����� �߰��� ���,
		pq->front = newNode;
		pq->rear = newNode; // front�� rear�� ��� �� ��带 ����Ű��
	}
	else { // �� ��° ������ ����� �߰��� ���,
		pq->rear->next = newNode;
		pq->rear = newNode; // ����Ʈ�� ������ �� ��� �߰��ϰ� front�� �״��, rear�� �� ��带 ����Ű��
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

	delNode = pq->front; // ������ ����� �ּҰ� �ӽ� ����
	retData = pq->front->data; // ������ ����� ������ �ӽ� ����
	pq->front = pq->front->next; // front�� ���� ��带 ����Ű��

	free(delNode); // ��� ����

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
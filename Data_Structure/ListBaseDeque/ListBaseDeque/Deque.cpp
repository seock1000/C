#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// initialize deque
// input : pointer of deque
// output : void;
void DequeInit(Deque* pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL; // ������ ���� head�� tail�� ��� NULL�� �ʱ�ȭ
}

// check if deque is empty or not
// input : pointer of deque
// output : TURE(1) if the deque is empty, FALSE(0) if the deque isn't empty
int DQIsEmpty(Deque* pdeq) {

	if (pdeq->head == NULL) // head�� NULL�̸� empty
		return TRUE;
	else
		return FALSE;
}

// insert data to head of deque
// input : pointer of deque and data to insert
// output : void
void DQAddFirst(Deque* pdeq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // ��� ����
	newNode->data = data; // ��忡 ������ ����

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq)) // deque�� empty�̸�
		pdeq->tail = newNode; // tail�� �� ��带 ����Ű��
	else  // deque�� empty�� �ƴϸ�
		pdeq->head->prev = newNode; // ������ head�� ����

	newNode->prev = NULL; //  �� ��尡 ����Ʈ�� head�̹Ƿ� prev�� NULL
	pdeq->head = newNode; // �� ��带 head�� �߰�
}

// inset data to tail of deque
// input : pointer of deque and data to insert
// output : void
void DQAddLast(Deque* pdeq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // ��� ����
	newNode->data = data;

	newNode->prev = pdeq->tail; 

	if (DQIsEmpty(pdeq)) // deque�� empty�̸�
		pdeq->head = newNode; // head�� �� ��带 ����Ű��
	else  // deque�� empty�� �ƴϸ�
		pdeq->tail->next = newNode; // �� ���� ���� tail�� ����

	newNode->next = NULL; // �� ��尡 ����Ʈ�� tail�̹Ƿ� next�� NULL
	pdeq->tail = newNode; // tail�� �� ��带 ����Ű��
}

// delete first data of deque
// input : pointer of deque
// output : deleted data
Data DQRemoveFirst(Deque* pdeq) {
	Node* rnode;
	Data rdata;

	if (DQIsEmpty(pdeq)) {
		printf("Dequeue Memory Error!\n");
		exit(-1);
	}

	rnode = pdeq->head;
	rdata = rnode->data; // ������ ����� ���� ����
	pdeq->head = pdeq->head->next;
	free(rnode); // ��� ����

	if (pdeq->head == NULL) // ��� ������ empty�̸�
		pdeq->tail = NULL; // tail�� NULL�� ����Ű��
	else // empty�� �ƴϸ�
		pdeq->head->prev = NULL; // ���ο� head�� prev�� NULL�� ����Ű��

	return rdata;
}

// delete first data of deque
// input : pointer of deque
// output : deleted data
Data DQRemoveLast(Deque* pdeq) {
	Node* rnode;
	Data rdata;

	if (DQIsEmpty(pdeq)) {
		printf("Dequeue Memory Error!\n");
		exit(-1);
	}

	rnode = pdeq->tail;
	rdata = rnode->data; // ������ ����� ���� ����
	pdeq->tail = pdeq->tail->prev;
	free(rnode); // ��� ����
	
	if (pdeq->tail == NULL) // ��� ������ empty�̸� 
		pdeq->head = NULL; // head�� NULL�� ����Ű��
	else // empty�� �ƴϸ�
		pdeq->tail->next = NULL; // ���ο� tail�� next�� NULL�� ����Ű��

	return rdata;
}

// get fisrt data of deque without deletion
// input : pointer of deque
// output : first data
Data DQGetFirst(Deque* pdeq) {

	if (DQIsEmpty(pdeq)) {
		printf("Dequeue Memory Error!\n");
		exit(-1);
	}

	return pdeq->head->data;
}

// get last data of deque without deletion
// input : pointer of deque
// output : last data
Data DQGetLast(Deque* pdeq) {

	if (DQIsEmpty(pdeq)) {
		printf("Dequeue Memory Error!\n");
		exit(-1);
	}

	return pdeq->tail->data;
}

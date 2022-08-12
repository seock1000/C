#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// initialize deque
// input : pointer of deque
// output : void;
void DequeInit(Deque* pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL; // 포인터 변수 head와 tail을 모두 NULL로 초기화
}

// check if deque is empty or not
// input : pointer of deque
// output : TURE(1) if the deque is empty, FALSE(0) if the deque isn't empty
int DQIsEmpty(Deque* pdeq) {

	if (pdeq->head == NULL) // head가 NULL이면 empty
		return TRUE;
	else
		return FALSE;
}

// insert data to head of deque
// input : pointer of deque and data to insert
// output : void
void DQAddFirst(Deque* pdeq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 노드 생성
	newNode->data = data; // 노드에 데이터 저장

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq)) // deque가 empty이면
		pdeq->tail = newNode; // tail이 새 노드를 가리키게
	else  // deque가 empty가 아니면
		pdeq->head->prev = newNode; // 기존의 head와 연결

	newNode->prev = NULL; //  새 노드가 리스트의 head이므로 prev는 NULL
	pdeq->head = newNode; // 새 노드를 head에 추가
}

// inset data to tail of deque
// input : pointer of deque and data to insert
// output : void
void DQAddLast(Deque* pdeq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // 노드 생성
	newNode->data = data;

	newNode->prev = pdeq->tail; 

	if (DQIsEmpty(pdeq)) // deque가 empty이면
		pdeq->head = newNode; // head가 새 노드를 가리키게
	else  // deque가 empty가 아니면
		pdeq->tail->next = newNode; // 새 노드와 기존 tail을 연결

	newNode->next = NULL; // 새 노드가 리스트의 tail이므로 next는 NULL
	pdeq->tail = newNode; // tail이 새 노드를 가리키게
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
	rdata = rnode->data; // 삭제할 노드의 정보 저장
	pdeq->head = pdeq->head->next;
	free(rnode); // 노드 삭제

	if (pdeq->head == NULL) // 노드 삭제후 empty이면
		pdeq->tail = NULL; // tail이 NULL을 가리키게
	else // empty가 아니면
		pdeq->head->prev = NULL; // 새로운 head의 prev가 NULL을 가리키게

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
	rdata = rnode->data; // 삭제할 노드의 정보 저장
	pdeq->tail = pdeq->tail->prev;
	free(rnode); // 노드 삭제
	
	if (pdeq->tail == NULL) // 노드 삭제후 empty이면 
		pdeq->head = NULL; // head가 NULL을 가리키게
	else // empty가 아니면
		pdeq->tail->next = NULL; // 새로운 tail의 next가 NULL을 가리키게

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

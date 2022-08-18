#include "PriorityQueue.h"

void PQueueInit(Queue* pq, PriorityComp pc) {
	HeapInit(pq, pc);
}

int QIsEmpty(Queue* pq) {
	return HIsEmpty(pq);
}

void Enqueue(Queue* pq, HData data) {
	HInsert(pq, data);
}

HData Dequeue(Queue* pq) {
	return HDelete(pq);
}
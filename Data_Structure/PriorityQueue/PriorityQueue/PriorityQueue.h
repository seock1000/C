#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef Heap PriorityQueue;
typedef PriorityQueue Queue;

void PQueueInit(Queue* pq, PriorityComp pc);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, HData data);
HData Dequeue(Queue* pq);

#endif
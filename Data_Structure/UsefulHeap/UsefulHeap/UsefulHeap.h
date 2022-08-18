#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
// d1 < d2이면 0보다 큰 값, d1 > d2이면 0보다 작은 값, d1 == d2이면 0 반환
typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap {
	PriorityComp comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif 

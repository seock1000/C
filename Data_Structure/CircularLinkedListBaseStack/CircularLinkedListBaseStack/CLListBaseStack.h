#ifndef __CLLB_STACK_H__
#define __CLLB_STACK_H__

#define TRUE 1
#define FALSE 0

#include "CLinkedList.h"

typedef List CLListStack;

typedef CLListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif

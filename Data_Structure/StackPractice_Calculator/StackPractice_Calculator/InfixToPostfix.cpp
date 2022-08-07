#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// return the informaition of operator's priority as integer
// input : one operator as char
// output : 5 if * or /, 3 if + or -, 1 if (, -1 otherwise
int GetOpPrec(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5; // 가장 높은 우선순위
	case '+':
	case '-':
		return 3; // 두번째로 높은 우선순위
	case '(':
		return 1; // 가장 낮은 우선순위
	}
	return -1; // 잘못된 연산자
}

// Compare priorities of two operators
// input : two operator
// output : 1 if the first parameter has higher priority, -1 if second parameter has higher priority, 0 ohterwise 
int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

// convert infix to postfix
// input : infix expression as string
// output : void
void ConvToRPNExp(char exp[]) { 
	Stack stack; // 변환에 이용할 스택 선언
	int expLen = strlen(exp); // 전달받은 문자열의 길이
	char* convExp = (char*)malloc(expLen + 1); // 변환된 수식을 담을 메모리 공간 할당

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // 할당된 배열 0으로 초기화
	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i]; // 전달받은 수식을 한 문자씩 저장
		if (isdigit(tok)) { // 해당 문자가 숫자이면
			convExp[idx++] = tok; // 그대로 이동
		}
		else { // 연산자일 경우
			switch (tok)
			{
			case '(': // ( 이면, 스택에 push
				SPush(&stack, tok);
				break;

			case ')': // ) 이면, ( 가 나올 때까지 스택의 연산자를 pop
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+':
			case'-':
			case '*':
			case '/': // 이 외의 연산자이면, 스택의 연산자와 비교하여 스택의 연산자의 우선순위가 높으면 pop, 낮으면 새 연산자 push
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack)) // 스택에 남은 연산자 모두 pop
		convExp[idx++] = SPop(&stack);

	strcpy_s(exp, sizeof(char)*(strlen(convExp)+1), convExp); // 변환된 수식을 전달받은 배열에 저장
	free(convExp); // 변환된 수식을 담는 공간 할당 해제
}



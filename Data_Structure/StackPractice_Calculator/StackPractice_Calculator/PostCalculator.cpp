#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// calculate postfix expression
// input : postfix expression
// output : result of calculating
int EvalRPNExp(char exp[]) {
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i]; // 후위 표기법 수식을 앞에서 부터 하나씩
		if (isdigit(tok)) { // 피연산자(숫자)이면 push
			SPush(&stack, tok - '0');
		}
		else { // 연산자이면,
			op2 = SPop(&stack);
			op1 = SPop(&stack); // 스택에서 두 개의 피연산자를 pop
			switch (tok) {
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			} // 연산자의 종류에 따라 계산
		}
	}

	return SPop(&stack); // 마지막 연산결과 스택으로부터 반환
}
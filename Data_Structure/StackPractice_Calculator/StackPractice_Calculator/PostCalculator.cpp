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
		tok = exp[i]; // ���� ǥ��� ������ �տ��� ���� �ϳ���
		if (isdigit(tok)) { // �ǿ�����(����)�̸� push
			SPush(&stack, tok - '0');
		}
		else { // �������̸�,
			op2 = SPop(&stack);
			op1 = SPop(&stack); // ���ÿ��� �� ���� �ǿ����ڸ� pop
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
			} // �������� ������ ���� ���
		}
	}

	return SPop(&stack); // ������ ������ �������κ��� ��ȯ
}
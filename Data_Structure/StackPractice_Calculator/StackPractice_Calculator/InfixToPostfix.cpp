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
		return 5; // ���� ���� �켱����
	case '+':
	case '-':
		return 3; // �ι�°�� ���� �켱����
	case '(':
		return 1; // ���� ���� �켱����
	}
	return -1; // �߸��� ������
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
	Stack stack; // ��ȯ�� �̿��� ���� ����
	int expLen = strlen(exp); // ���޹��� ���ڿ��� ����
	char* convExp = (char*)malloc(expLen + 1); // ��ȯ�� ������ ���� �޸� ���� �Ҵ�

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // �Ҵ�� �迭 0���� �ʱ�ȭ
	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i]; // ���޹��� ������ �� ���ھ� ����
		if (isdigit(tok)) { // �ش� ���ڰ� �����̸�
			convExp[idx++] = tok; // �״�� �̵�
		}
		else { // �������� ���
			switch (tok)
			{
			case '(': // ( �̸�, ���ÿ� push
				SPush(&stack, tok);
				break;

			case ')': // ) �̸�, ( �� ���� ������ ������ �����ڸ� pop
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
			case '/': // �� ���� �������̸�, ������ �����ڿ� ���Ͽ� ������ �������� �켱������ ������ pop, ������ �� ������ push
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack)) // ���ÿ� ���� ������ ��� pop
		convExp[idx++] = SPop(&stack);

	strcpy_s(exp, sizeof(char)*(strlen(convExp)+1), convExp); // ��ȯ�� ������ ���޹��� �迭�� ����
	free(convExp); // ��ȯ�� ������ ��� ���� �Ҵ� ����
}



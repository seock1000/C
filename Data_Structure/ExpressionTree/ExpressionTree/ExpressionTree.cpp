#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../BinaryTree/BinaryTree/BinaryTree.h"
#include "ListBaseStack.h"

// make expression tree of postfix expression
// input : postfix expression as string
// output : expression tree
BTreeNode* MakeExpTree(char exp[]) {
	Stack stack; 
	BTreeNode* pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		pnode = MakeBTreeNode(); // ��� ����

		if (isdigit(exp[i])) { // �ǿ������̸�
			SetData(pnode, exp[i] - '0'); // ��忡 ������ ����
		}
		else { // �������̸�
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack)); // ���ÿ��� �ǿ����� �ΰ��� ���� child�� �����ϰ�
			SetData(pnode, exp[i]); // ��忡 ������ ����
		}
		SPush(&stack, pnode); // �ٽ� ���ÿ� push
	}

	return SPop(&stack); // ��� ���� ������ ���ÿ� ���� Ʈ�� ��ȯ
}

// evaluate expression tree
// input : expression tree
// output : result of evaluate
int EvaluateExpTree(BTreeNode* bt) {
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // leaf node�̸�(= �ǿ�����)
		return GetData(bt); // ������ ��ȯ

	//leaf node�� �ƴϸ�(= ������)
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt)); // ���ȣ��� ���� ���� level�� leaf node���� ����

	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

// print data to consol
// input : integer
// output : void
void ShowNodeData(int data) {
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

// print expression of expression tree as prefix
// input : expression tree
// output : void
void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);
}

// print expression of expression tree as infix
// input : expression tree
// output : void
void ShowInfixTypeExp(BTreeNode* bt) {
	if (bt == NULL) // ����� Ż�� ����
		return;
	if (bt->left != NULL || bt->right != NULL) // ��尡 child�� ������ ��쿡�� �Ұ�ȣ ���
		printf("( ");

	// ���ȣ��
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != NULL || bt->right != NULL)
		printf(") ");
}

// print expression of expression tree as postfix
// input : expression tree
// output : void
void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}
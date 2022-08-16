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
		pnode = MakeBTreeNode(); // 노드 생성

		if (isdigit(exp[i])) { // 피연산자이면
			SetData(pnode, exp[i] - '0'); // 노드에 데이터 저장
		}
		else { // 연산자이면
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack)); // 스택에서 피연산자 두개를 꺼내 child로 연결하고
			SetData(pnode, exp[i]); // 노드에 데이터 저장
		}
		SPush(&stack, pnode); // 다시 스택에 push
	}

	return SPop(&stack); // 모든 과정 종료후 스택에 남은 트리 반환
}

// evaluate expression tree
// input : expression tree
// output : result of evaluate
int EvaluateExpTree(BTreeNode* bt) {
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // leaf node이면(= 피연산자)
		return GetData(bt); // 데이터 반환

	//leaf node가 아니면(= 연산자)
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt)); // 재귀호출로 가장 높은 level의 leaf node부터 연산

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
	if (bt == NULL) // 재귀의 탈출 조건
		return;
	if (bt->left != NULL || bt->right != NULL) // 노드가 child를 가지는 경우에만 소괄호 출력
		printf("( ");

	// 재귀호출
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
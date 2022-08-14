#include <stdio.h>
#include "BinaryTree.h"

int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode(); // 노드 생성

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4); // 데이터 저장

	MakeLeftSubTree(bt1, bt2); // bt2를 bt1의 왼쪽 자식 노드로
	MakeRightSubTree(bt1, bt3); // bt3를 bt1의 오른쪽 자식 노드로
	MakeLeftSubTree(bt2, bt4); // bt4를 bt2의 왼쪽 자식 노드로

	printf("  %d \n", GetData(bt1));
	printf(" %d %d\n", GetData(GetLeftSubTree(bt1)), GetData(GetRightSubTree(bt1)));
	printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}
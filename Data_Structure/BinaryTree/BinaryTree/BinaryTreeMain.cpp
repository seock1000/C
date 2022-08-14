#include <stdio.h>
#include "BinaryTree.h"

int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode(); // ��� ����

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4); // ������ ����

	MakeLeftSubTree(bt1, bt2); // bt2�� bt1�� ���� �ڽ� ����
	MakeRightSubTree(bt1, bt3); // bt3�� bt1�� ������ �ڽ� ����
	MakeLeftSubTree(bt2, bt4); // bt4�� bt2�� ���� �ڽ� ����

	printf("  %d \n", GetData(bt1));
	printf(" %d %d\n", GetData(GetLeftSubTree(bt1)), GetData(GetRightSubTree(bt1)));
	printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}
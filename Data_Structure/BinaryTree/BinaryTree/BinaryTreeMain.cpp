#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode(); // ��� ����

	SetData(bt1, 1); SetData(bt2, 2);
	SetData(bt3, 3); SetData(bt4, 4);
	SetData(bt5, 5); SetData(bt6, 6); // ������ ����

	MakeLeftSubTree(bt1, bt2); // bt2�� bt1�� ���� �ڽ� ����
	MakeRightSubTree(bt1, bt3); // bt3�� bt1�� ������ �ڽ� ����
	MakeLeftSubTree(bt2, bt4); // bt4�� bt2�� ���� �ڽ� ����
	MakeRightSubTree(bt2, bt5); // bt5�� bt2�� ������ �ڽ� ����
	MakeLeftSubTree(bt3, bt6); // bt6�� bt3�� ���� �ڽ� ����

	printf("Preorder : ");
	PreorderTraverse(bt1, ShowIntData);
	printf("\n");

	printf("Inorder : ");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");

	printf("Postorder : ");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n\n");

	printf("Delete sub tree bt2\n");
	DeleteTree(bt2);
	printf("Deletion Success!!\n\n");

	return 0;
}

void ShowIntData(int data) {
	printf("%d ", data);
}
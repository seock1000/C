#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// make new node's memory space
// input : void
// output : pointer of node
BTreeNode* MakeBTreeNode() {
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode)); // 메모리 공간 할당
	nd->left = NULL;
	nd->right = NULL; // left, right NULL로 초기화
	return nd;
}

// get data of node
// input : pointer of node
// output : data of node
BTData GetData(BTreeNode* bt) {
	return bt->data;
}

// set data of node
// input : pointer of node and data to set
// output : void
void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

// get pointer of left sub tree
// input : pointer of node;
// output : pointer of node's left sub tree
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

// get pointer of right sub tree
// input : pointer of node
// output pointer of node's right sub tree
BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

// make tree to left sub tree of node
// input : pointer of node and pointer of tree for linking
// output : void
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL) // left sub tree 존재하면 삭제
		free(main->left);
	main->left = sub;
}

// make tree to right sub tree of node
// input : pointer of node and pointer of tree for linking
// output : void
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL) // right sub tree 존재하면 삭제
		free(main->right);
	main->right = sub;
}

void DeleteTree(BTreeNode* bt) {
	if (bt == NULL)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("delete data : %d\n", bt->data);
	free(bt);
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);

}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "../../BinaryTree/BinaryTree/BinaryTree.h"
#include "ListBaseStack.h"

BTreeNode* MakeExpTree(char exp[]); // ���� Ʈ�� ����
int EvaluateExpTree(BTreeNode* bt); // ���� Ʈ�� ���

void ShowPrefixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���

#endif
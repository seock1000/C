#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("Preorder : ");
	ShowPrefixTypeExp(eTree);
	printf("\n");

	printf("Inorder : ");
	ShowInfixTypeExp(eTree);
	printf("\n");

	printf("Postorder : ");
	ShowPostfixTypeExp(eTree);
	printf("\n");

	printf("result : ");
	printf("%d", EvaluateExpTree(eTree));
	printf("\n");

	return 0;
}
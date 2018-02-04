#include "head.h"


int main() {
	int leaf, height;
	nodePointer tree = CreateTree();
	nodePointer stack[MAX], que[MAX], temp;
	printf("%s\n", "Inorder:");
	inorder(tree);
	printf("\n");
	printf("%s\n", "Preorder:");
	preorder(tree);
	printf("\n");
	printf("%s\n", "Postorder:");
	postorder(tree);
	printf("\n");
	printf("%s\n", "Inorder(Iterative verison):");
	iter_inorder(tree);
	printf("\n");
	printf("%s\n", "Levelorder:");
	level_order(tree);
	printf("\n");
	leaf = leafNumber(tree);
	printf("%s%d\n", "Leaf number: ", leaf);
	height = treeHeight(tree);
	printf("%s%d\n", "Height of the tree: ", height);
	return 0;
}

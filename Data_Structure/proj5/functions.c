#define MAX 50


nodePointer CreateTree() {
	nodePointer temp;
	char ch;
	scanf("%c", &ch);
	if (ch == '#') temp = NULL;
	else {
		temp = (nodePointer)malloc(sizeof(nodeTree));
		temp->data = ch;
		temp->left = CreateTree();
		temp->right = CreateTree();
	}
	return temp;
}

void inorder(nodePointer tree) {
	if (tree) {
		inorder(tree->left);
		printf("%c", tree->data);
		inorder(tree->right);
	}
}

void preorder(nodePointer tree) {
	if (tree) {
		printf("%c", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void postorder(nodePointer tree) {
	if (tree) {
		postorder(tree->left);
		postorder(tree->right);
		printf("%c", tree->data);
	}
}

void iter_inorder(nodePointer tree) {
	int top = -1;
	nodePointer stack[MAX];
	for (;;) {
		for(; tree; tree = tree->left)
			Push(stack, tree);
		tree = Pop(stack);
		if (!tree) break;
		printf("%c", tree->data);
		tree = tree->right;
	}
}

void level_order(nodePointer tree) {
	nodePointer que[MAX];
	if (!tree) return;
	EnQueue(que, tree);
	for (;;) {
		tree = DeQueue(que);
		if (tree) {
			printf("%c", tree->data);
			if (tree->left)
				EnQueue(que, tree->left);
			if (tree->right)
				EnQueue(que, tree->right);
		} else break;
	}
}

int leafNumber(nodePointer tree) {
	int leaf = 0;
	if (tree) {
		if (tree->left) {
			leaf += leafNumber(tree->left);
		}
		if (tree->right) {
			leaf += leafNumber(tree->right);
		}
		if (tree->right == NULL && tree->left == NULL)
			leaf++;
	}
	return leaf;
}

int treeHeight(nodePointer tree) {
	int depth = 0, depleft = 0, depright = 0;
	if (tree) {
		depth++;
		depleft = treeHeight(tree->left);
		depright = treeHeight(tree->right);
		depth += (depleft >= depright ? depleft : depright);
	}
	return depth;
}

#define MAX_NODES 50
int top = -1;


nodePointer Create(char data) {
	nodePointer temp;
	temp = (nodePointer)malloc(sizeof(nodePointer));
	temp->left = NULL, temp->right = NULL;
	if (data)
		temp->data = data;
	else temp->data = 0;
	return temp;
}

int IsFull(nodePointer stk) {
	int Nfull = 0;
	if (!(stk)) {
		return 0;
	} else {
		if (top >= MAX_NODES)
			return 1;
	}
	return 0;
}

int IsEmpty(nodePointer stk) {
	if ((!stk)) {
		return 1;
	}
	else return 0;
}

void Push(nodePointer stack[], nodePointer node) {
	if (top < MAX_NODES) {
		top++;
		stack[top] = node;
	}
	else {
		printf("%s\n", "Memory Exceeded.(Tree)");
		exit(EXIT_FAILURE);
	}
}

nodePointer Pop(nodePointer stack[]) {
	nodePointer temp = NULL;
	if (top >= 0) {
		temp = stack[top];
		top--;
	}
	return temp;
}

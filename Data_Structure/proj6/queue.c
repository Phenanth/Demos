#define MAX_QUEUE 50
int front = 0, rear = 0;


nodePointer *CreateQueue() {
	nodePointer *temp;
	//int i;
	temp = (nodePointer *)malloc(MAX_QUEUE * sizeof(nodePointer));
	return temp;
}

int isQueueEmpty() {
	if ((front == 0 && rear == 0) || rear == front)
		return 1;
	else return 0;
}

void DisposeQueue(nodePointer *que) {
	free(que);
	front = 0, rear = 0;
}

void MakeEmpty(nodePointer que[]) {
	int i;
	for (i = 0; i < MAX_QUEUE; i++) {
		que[i]->vertex = 0;
	}
	rear = 0, front = 0;
}

void EnQueue(nodePointer que[], nodePointer data) {
	rear = (rear + 1) % MAX_QUEUE;
	if (rear == front) {
		printf("%s\n", "Memory Exceeded.");
		exit(EXIT_FAILURE);
	}
	que[rear] = data;
}

nodePointer Front(nodePointer que[]) {
	nodePointer temp = NULL;
	if (!isQueueEmpty()) {
		temp = que[rear - 1];
	}
	return temp;
}

nodePointer DeQueue(nodePointer que[]) {
	nodePointer temp = NULL;
	if (front != rear) {
		front = (front + 1) % MAX_QUEUE;
		temp = que[front];
	}
	return temp;
}

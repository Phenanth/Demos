/*

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct nodeTree{
	char data;
	struct nodeTree *left;
	struct nodeTree *right;
}nodeTree;
typedef nodeTree *nodePointer;

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

void swapTree(nodePointer tree) {
	nodePointer swp = NULL;
	swp = tree->left;
	tree->left = tree->right;
	tree->right = swp;
	if (tree->left)
		swapTree(tree->left);
	if (tree->right)
		swapTree(tree->right);
}

//  ABD#G##E##CF#H###

int main() {

	nodePointer tree = CreateTree(), temp = NULL;
	printf("%s\n", "Inorder:");
	inorder(tree);
	printf("\n");

	printf("%s\n", "Preorder:");
	preorder(tree);
	printf("\n");

	swapTree(tree);	

	printf("%s\n", "Swaped inorder:");
	inorder(tree);
	printf("\n");

	printf("%s\n", "Preorder:");
	preorder(tree);
	printf("\n");
	return 0;
}

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

typedef struct heap {
	int data;
	/*
	other field.
	*/
}Heap;                                                                           
typedef struct heap *heapPointer;


void PushMaxHeap(Heap heap[], int *n, Heap item) {
	int i, j, top, bottom, mid, tmp;
	if (*n >= MAX) {
		fprintf(stderr, "Heap is full. \n");
		exit(EXIT_FAILURE);
	}
	i = ++(*n);
	top = 0, bottom = 0;
	for (j = 0; j < i; j *= 2)
		bottom++;

	do{
		mid = (top + bottom) / 2;
		printf("mid:%d\n", mid);
		tmp = pow(2, mid);
		if (heap[tmp].data < item.data) {
			int temp = i;
			while (temp > tmp) {
				heap[i].data = heap[temp/2].data;
				temp /= 2;
			}
			bottom = mid;
		} else if (heap[tmp].data > item.data) {
			top = mid;
		}
		i = tmp;
		tmp = pow(2, mid / 2);
	} while ((i != 1) && (item.data > heap[tmp].data));
	heap[i].data = item.data;
}

void PushMinHeap(Heap heap[], int *n, Heap item) {
	int i;
	if (*n >= MAX) {
		fprintf(stderr, "Heap is full. \n");
		exit(EXIT_FAILURE);
	}
	i = ++(*n);
	while ((i != 1) && (item.data < heap[i/2].data)) {
		heap[i].data = heap[i/2].data;
		i /= 2;
	}
	heap[i].data = item.data;
}

Heap *CreateMaxHeap() {
	int temp = 0, n = 0;
	Heap *heap;
	heap = (Heap *)malloc(sizeof(Heap) * MAX);
	scanf("%d", &temp);
	while (temp != -1) {
		Heap tmp;
		tmp.data = temp;
		PushMaxHeap(heap, &n, tmp);
		scanf("%d", &temp);
	}
	return heap;
}

Heap *CreateMinHeap() {
	int temp = 0, n = 0;
	Heap *heap;
	heap = (Heap *)malloc(sizeof(Heap) * MAX);
	scanf("%d", &temp);
	while (temp != -1) {
		Heap tmp;
		tmp.data = temp;
		PushMinHeap(heap, &n, tmp);
		scanf("%d", &temp);
	}
	return heap;
}	

// 7 16 49 82 5 31 6 2 44 -1

int main() {

	int i = 1;
	Heap *minHeap, *maxHeap;
	//minHeap = CreateMinHeap();
	maxHeap = CreateMaxHeap();
	minHeap++, maxHeap++;
	/*
	while (i < 10) {
		printf("%d ", (*minHeap).data);
		minHeap++, i++;
	}
	printf("\n");
	*/
	i = 1;
	while (i < 10) {
		printf("%d ", (*maxHeap).data);
		maxHeap++, i++;
	}
	printf("\n");

	return 0;
}
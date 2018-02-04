#include <stdio.h>
#include <stdlib.h>


// stack:

typedef struct nodeTree{
	char data;
	struct nodeTree *left;
	struct nodeTree *right;
}nodeTree;
typedef nodeTree *nodePointer;

nodePointer Create(char data);
int IsFull(nodePointer stk);
int IsEmpty(nodePointer stk);
nodePointer Pop(nodePointer stack[]);
void Push(nodePointer stack[], nodePointer node);

// queue:

nodePointer *CreateQueue();
int isQueueEmpty();
void DisposeQueue(nodePointer *que);
void MakeEmpty(nodePointer que[]);
void EnQueue(nodePointer que[], nodePointer data);
nodePointer Front(nodePointer que[]);
nodePointer DeQueue(nodePointer que[]);

// functions:

nodePointer CreateTree();
void inorder(nodePointer tree);
void preorder(nodePointer tree);
void postorder(nodePointer tree);
void iter_inorder(nodePointer tree);
int leafNumber(nodePointer tree);
int treeHeight(nodePointer tree);

#include "stack.c"
#include "queue.c"
#include "functions.c"

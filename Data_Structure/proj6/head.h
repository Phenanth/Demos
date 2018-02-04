#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50


typedef struct node {
	int vertex;
	int weight;
	struct node *next;
}Node;
typedef struct node *nodePointer;


FILE *read, *write;

int n = 0, vertexs = 0, edges = 0;
nodePointer graph[MAX_VERTICES];

nodePointer list;
short int visited[MAX_VERTICES];
short int notConnected[MAX_VERTICES];


// Queue:
nodePointer *CreateQueue();
int isQueueEmpty();
void DisposeQueue(nodePointer *que);
void MakeEmpty(nodePointer que[]);
void EnQueue(nodePointer que[], nodePointer data);
nodePointer Front(nodePointer que[]);
nodePointer DeQueue(nodePointer que[]);

// Function:
void init();
void clearVisited();
void printGraph();
void dfs(int v);
void bfs(int v); 
void connected();
void prim(int v);
void shortest(int v);
void output();
void trash();


#include "queue.c"
#include "function.c"

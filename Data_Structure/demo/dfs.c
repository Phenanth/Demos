#include <stdio.h>
#include <stdlib.h>
#define MAX 50

FILE *read;
short int vertexs, edges, visited[MAX];
int **graph;

int **generateTemplate() {

	int **temp, i;
	temp = (int **)malloc(vertexs * sizeof(int *));

	for (i = 0; i < vertexs; i++)
		temp[i] = (int *)malloc(vertexs * sizeof(int));

	return temp;

}

// 清空visited[]
void clearVisited() {
	short int i;
	for (i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
}

void init() {

	int **graph, v1, v2, w, i, j;

	read = fopen("input.txt", "r");
	if (read == NULL) {
		fprintf(stderr, "%s\n", "The file doesn't exist.");
		exit(EXIT_FAILURE);
	}
	
	fscanf(read, "%hd %hd", &vertexs, &edges);

	graph = generateTemplate();

	for (i = 0; i < vertexs; i++) {
		for (j = 0; j < vertexs; j++) {
			graph[i][j] = 0;
		}
	}

	while (fscanf(read, "%d %d %d", &v1, &v2, &w) != EOF)
		graph[v1][v2] = w;

	clearVisited();

	for (i = 0; i < vertexs; i++) {
		for (j = 0; j < vertexs; j++) {
			printf("%3d", graph[i][j]);
			if (j == vertexs - 1) {
				printf("\n");
			}
		}
	}

	for (i = 0; i < vertexs; i++) {
		printf("%2d", visited[i]);
	}
	printf("\n");
}

void dfs(int v) {

	int j;
	printf("V%d  ", v);
	for (j = 0; j < vertexs; j++){
		printf("visited:%d, graph[][]:%d\n", visited[j], graph[v][j]);
		if (!visited[j] && graph[v][j] != 0) {
			dfs(j);
		}
	}
}

void trash() {
	fclose(read);
}

int main() {
	init();
	dfs(0);
	printf("\n");
	trash();
	return 0;
}
// 初始化
void init() {
	int i;
	int tmpv, tmpe, tmpw;

	list = (nodePointer)malloc(sizeof(Node));

	// 文件打开操作
	read = fopen("input.txt", "r");
	write = fopen("output.txt", "w");
	if (read == NULL || write == NULL) {
		fprintf(stderr, "Unknown Error.");
		exit(EXIT_FAILURE);
	}
	fscanf(read, "%d", &vertexs);
	fscanf(read, "%d", &edges);

	// 初始化空图，可以抽成初始化函数
	for (i = 0; i < MAX_VERTICES; i++) {
		graph[i] = NULL;
	}

	clearVisited();

	// 添加边与点数
	while(fscanf(read, "%d %d %d", &tmpv, &tmpe, &tmpw) != EOF) {
		nodePointer w, end;
		w = (nodePointer)malloc(sizeof(Node));
		w->vertex = tmpe, w->weight = tmpw, w->next = NULL;
		end = graph[tmpv];
		while (end != NULL && end->next != NULL) { // 修改
			end = end->next;
		}
		if (end == NULL) {
			graph[tmpv] = w;
		} else {
			end->next = w;
		}
	}
}

// 清空visited[]
void clearVisited() {
	int i;
	for (i = 0; i < MAX_VERTICES; i++) {
		visited[i] = 0;
	}
}

// 打印图
void printGraph() {

	int i;
	nodePointer tmp;

	for (i = 0; i < vertexs; i++) {

		fprintf(write, "%d:", i);

		for (tmp = graph[i]; tmp; (tmp = tmp->next))
			fprintf(write, "%3d", tmp->vertex);

		fprintf(write, "\n");

	}

}

// dfs
void dfs(int v) {

	nodePointer w;
	int i, j;

	visited[v] = 1;
	fprintf(write, "V%d  ", v);

	for (w = graph[v]; w; (w = w->next)) {

		if (!visited[w->vertex])
			dfs(w->vertex);

	}

}

// bfs
void bfs(int v) {

	int count = 0, i;
	nodePointer w, que[MAX_VERTICES], temp;
	front = 0, rear = 0;

	fprintf(write, "V%d  ", v);
	visited[v] = 1;

	temp = (nodePointer)malloc(sizeof(Node));
	temp->vertex = v;
	EnQueue(que, temp);

	while (!isQueueEmpty()) {

		if (count == vertexs)
			break;
		v = DeQueue(que)->vertex;

		for (w = graph[v]; w; (w = w->next))

			if (!visited[w->vertex]) {

				fprintf(write, "V%d  ", w->vertex);
				EnQueue(que, w);
				visited[w->vertex] = 1;
				count++;

			}
	}

	fprintf(write, "\n");

}

// 记录图连通情况
void connected() {

	int i;
	notConnected[vertexs] = 0;

	for (i = 0; i < vertexs; i++) {

		if (visited[i])
			notConnected[i] = 0;
		else {
			notConnected[i] = 1;
			notConnected[vertexs]++;
		}

	}

}

// 返回prim算法下的最短路径中结点组成的链表
void prim(int v) {

	int min, count = 0, num;
	nodePointer ptr;

	list = (nodePointer)malloc(sizeof(nodePointer));
	list->vertex = v, list->weight = 0, list->next = NULL;
	connected();
	clearVisited();
	num = vertexs - notConnected[vertexs];

	while (1) {

		// 关于已经遍历过的结点判断存在不合理处,
		// 希望以后能够用第二小的方法降低错误率。
		if (visited[v]) { 
			v = ptr->next->vertex;
			continue;
		}
		count++;
		visited[v] = 1; 

		nodePointer end = list, tmp, n;
		min = graph[v]->weight;

		while (end->next)
			end = end->next;

		for (tmp = graph[v], ptr = graph[v]; tmp; (tmp = tmp->next)) {

			if (tmp->weight <= min) {
				min = tmp->weight;
				ptr = tmp;
			}

		}

		if (count == num)
			break;

		n = (nodePointer)malloc(sizeof(Node));
		n->vertex = ptr->vertex, n->weight = min, n->next = NULL;
		end->next = n;

		v = ptr->vertex;

	}

}

// 最短路径
void shortest(int v) {

	int i;

	prim(0);

	for (i = 1; i < vertexs; i++) {

		int weight = 0, min = 0;
		nodePointer tmp = list, temp = graph[0];

		while (temp) {

			if (temp->vertex == i) {
				min = temp->weight;
				break;
			}
			temp = temp->next;

		}

		while (tmp->vertex != i) {

			if (tmp->next)
				tmp = tmp->next;

			else {
				weight = 1000;
				break;
			}

			weight += tmp->weight;

		}

		if (min > weight || min == 0)
			min = weight;

		fprintf(write, "V%d: %d\n", i, min);

	}

}

// 向文档输出
void output() {
	
	printGraph();

	dfs(1);
	fprintf(write, "\n");

	clearVisited();
	bfs(1);

	shortest(0);
	
	printf("%s\n", "Operation successfully ended.");
}

// 关闭文件
void trash() {

	fclose(read);
	fclose(write);
	
}

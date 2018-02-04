/*
Data Structure 课程 实验7
Project7's main function
工程结构及调试方法请见 README.md
*/

#include "head.h"

int main() {

	FILE *fp;
	long *list;
	int n;
	clock_t start, end;

	fp = fopen(FILENAME, "r");
	if (fp == NULL) {
		fprintf(stderr, "%s\n", "Failed to open file.");
		exit(EXIT_FAILURE);
	}

	start = clock();
	fscanf(fp, "%d", &n);

	while (n != -1) {

		list = (long *)malloc((n + 1) * sizeof(long));
		readData(fp, list, n);

		printf("%s\n", "Origin:");
		printList(list, n);
		printf("%s\n", "In the passes:");

		InsertSort(list, n);

		//QuickSort(list, 1, n, n);

		//MergeSort(list, n);

		//HeapSort(list, n);

		printf("%s\n", "Result:");
		printList(list, n);
		printf("\n");

		free(list);

		fscanf(fp, "%d", &n);
	}

	end = clock();
	fclose(fp);

	printf("%f%s\n", (double)(end - start) / CLOCKS_PER_SEC, " seconds has passed.");

	return 0;
}

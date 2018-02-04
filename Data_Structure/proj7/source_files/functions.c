
void readData(FILE *fp, long *list, int n) {
	int i;
	for (i = 1; i <= n; i++) {
		fscanf(fp, "%ld", &list[i]);
	}

}

void printList(long *list, int n) {

	int i;
	for (i = 1; i <= n; i++) {
		printf("%6ld", list[i]);
	}
	printf("\n");

}

void swap(long *list, int pos1, int pos2) {

	long temp;
	temp = list[pos1];
	list[pos1] = list[pos2];
	list[pos2] = temp;

}

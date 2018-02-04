
void insert(long *list, int pos, long num) {

	list[0] = num;
	while (num < list[pos]) {
		list[pos + 1] = list[pos];
		pos--;
	}
	list[pos + 1] = num;

}

void InsertSort(long *list, int n) {

	int j;
	
	for (j = 2; j <= n; j++) {
		long temp = list[j];
		insert(list, (j - 1), temp);
		//printList(list, n);
	}

}

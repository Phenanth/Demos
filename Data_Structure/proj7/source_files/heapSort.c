
void adjust(long *list, int root, int n) {
	int child;
	long temp;
	temp = list[root];
	child = 2 * root;

	while (child <= n) {
		if ((child <= n) && (list[child] < list[child + 1])) {
			child++;
		}
		// 避免 child 下标越界进入已经排序过的部分
		if (temp > list[child] || child > n) {
			break;
		}
		else {
			list[child / 2] = list[child];
			child *= 2;
		}
	}

	list[child / 2] = temp;
}

void HeapSort(long *list, int n) {
	int i, j;

	for (i = n / 2; i > 0; i--) {
		adjust(list, i, n);
		//printList(list, n);
	}
	//printf("%s\n", "Second Part:");
	for (i = n - 1; i > 0; i--) {
		// 当只剩下两个数字时，判断相互关系
		if ((i > 1) || (i == 1 && list[1] > list[2])) {
			swap(list, 1, i + 1);
			//printList(list, n);
			adjust(list, 1, i);
		}
		//printList(list, n);
	}
}

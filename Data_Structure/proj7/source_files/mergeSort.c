
void merge(long *initList, long *mergedList, int left, int mid, int right) {
	int j, k, t;
	j = mid + 1;
	k = left;

	while (left <= mid && j <= right) {
		if (initList[left] <= initList[j]) {
			mergedList[k++] = initList[left++];
		} else {
			mergedList[k++] = initList[j++];
		}
	}

	if (left > mid) {
		for (t = j; t <= right; t++) {
			mergedList[t] = initList[t];
		}
	} else {
		for (t = left; t <= mid; t++) {
			mergedList[k + t - left] = initList[t];
		}
	}
}

void mergeOnePass(long *initList, long *mergedList, int n, int size) {
	int i, j;

	for (i = 1; i <= n - 2 * size + 1; i += 2 * size) {
		merge(initList, mergedList, i, i + size - 1, i + 2 * size - 1);
	}

	if (i + size - 1 < n) {
		merge(initList, mergedList, i, i + size - 1, n);
	} else {
		for (j = i; j <= n; j++) {
			mergedList[j] = initList[j];
		}
	}

}

void MergeSort(long *list, int n) {
	int size = 1;
	long *extra;

	extra = (long *)malloc((n + 1) * sizeof(long));
	while (size < n) {
		mergeOnePass(list, extra, n, size);
		//printList(extra, n);
		size *= 2;
		mergeOnePass(extra, list, n, size);
		//printList(list, n);
		size *= 2;
	}
}

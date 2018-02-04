
void QuickSort(long *list, int left, int right, int n) {
	long pivot;
	int i = 0, j = 0;

	if (left < right) {
		i = left, j = right + 1;
		pivot = list[left];
		do {

			do {
				i++;
			} while (list[i] < pivot);

			do {
				j--;
			} while (list[j] > pivot);

			if (i < j) {
				swap(list, i, j);
			}
			//printList(list, n);
		} while (i < j);
	}
	if (j && left) {
		swap(list, left, j);
		//printList(list, n);
		QuickSort(list, left, (j - 1), n);
		QuickSort(list, (j + 1), right, n);
	}
}

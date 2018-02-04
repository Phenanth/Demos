int iterativeSequentialSearch(int arr[], int n);
int recursiveSequentialSearch(int arr[], int n, int search);
int iterativeBinarySearch(int arr[], int n, int search);

int iterativeSequentialSearch(int arr[], int n) {
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == n) {
			found = 1;
			break;
		}
	}
	if (found == 0)
		return 0;
	else return 1;
}

int recursiveSequentialSearch(int arr[], int n, int search) {
	if (arr[n - 1] == search)
		return 1;
	if (n == 1)
		return 0;
	else return recursiveSequentialSearch(arr, n - 1, search);
}

int iterativeBinarySearch(int arr[], int n, int search) {
	int left = 0, right = n - 1, mid;
	while (left <= right) {
		mid = left + ((right - left) / 2);
		if (search < arr[mid]) {
			right = mid - 1;
		}
		else if (search > arr[mid]) {
			left = mid + 1;
		}
		else return mid;
	}
	return 0;
}
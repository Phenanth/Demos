#include <stdio.h>
#include <stdlib.h>

int *input(int* len);
int *merger(int arr1[], int arr2[], int len1, int len2);

void output(int arr[], int len);

int main() {
	int *arr1 = NULL, *arr2 = NULL, *arr3 = NULL, len1, len2;
	arr1 = input(&len1);
	arr2 = input(&len2);
	arr3 = merger(arr1, arr2, len1, len2);
	output(arr3, len1+len2);
	return 0;
}

int *input(int* len) {
	int i, *arr;
	printf("%s\n", "Input:");
	scanf("%d", len);
	arr = (int *)malloc(*len * sizeof(int));
	for (i = 0; i < *len; i++) {
		scanf("%d", &arr[i]);
	}
	return arr;
}

int *merger(int arr1[], int arr2[], int len1, int len2) {
	int *arr = (int *)malloc(len1 + len2 * sizeof(int));
	int start1, start2, count;
	for(start1 = 0, start2 = 0, count = 0; start1 < len1 && start2 < len2; count++){
		if(arr1[start1] < arr2[start2]){
			arr[count] = arr1[start1];
			start1++;
		} else if (arr1[start1] == arr2[start2]) {
			arr[count++] = arr1[start1];
			arr[count] = arr2[start2];
			start1++, start2++;
		} else {
			arr[count] = arr2[start2];
			start2++;
		}
	}
	int start, *arr_long;
	if (len1 < len2){
		start = start2;
		arr_long = arr2;
	} else {
		start = start1;
		arr_long = arr1;
	}
	while (count < len1+len2) {
		arr[count++] = arr_long[start++];
	}
	return arr;
}

void output(int arr[], int len) {
	int i;
	if (arr == NULL) {
		printf("%s\n", "Invalid memory.");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", "Output:");
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
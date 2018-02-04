#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILENAME "inputs/input.txt"


// Insert Sort:
void insert(long *list, int pos, long num);
void InsertSort(long *list, int n);

// Quick Sort:
void QuickSort(long *list, int left, int right, int n);

// Merge Sort:
void merge(long *initList, long *mergedList, int left, int mid, int right);
void mergeOnePass(long *initList, long *mergedList, int n, int size);
void MergeSort(long *list, int n);

// Heap Sort:
void adjust(long *list, int root, int n);
void HeapSort(long *list, int n);

// Functions:
void readData(FILE *fp, long *list, int n);
void printList(long *list, int n);
void swap(long *list, int pos1, int pos2);



#include "source_files/insertSort.c"
#include "source_files/quickSort.c"
#include "source_files/mergeSort.c"
#include "source_files/heapSort.c"
#include "source_files/functions.c"

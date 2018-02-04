
#include <stdio.h>
#define MAX 10


void Add(int deq[], int* p, int data, int front);
int Delete(int deq[], int* p, int front);

void printArray(int arr[]);

int main() {
	int deq[MAX] = { 0 }, pf = 0, pe = 0;
	printArray(deq);
	Add(deq, &pf, 4, 1);
	printArray(deq);
	Add(deq, &pe, 5, 0);
	printArray(deq);
	Delete(deq, &pf, 1);
	printArray(deq);
	Delete(deq, &pe, 0);
	printArray(deq);
	return 0;
}

void Add(int deq[], int* p, int data, int front) {
    // *p为队伍左端或右端的位置，front表示是队伍的左端
	int pos;
	if (*p >= MAX / 2 + 1) {
	    printf("%s\n", "Memory Exceeded.");
    } else {
    	if (front) {
    		pos = MAX / 2 - 1 - *p;
    		deq[pos] = data;
    	} else {
    		pos = MAX / 2 + *p;
    		deq[pos] = data;
    	}
    	(*p)++;
    }
}


int Delete(int deq[], int* p, int front) {
    // *p为队伍左端或右端的位置，front表示是队伍的左端
	int pos, temp = 0;
    if (*p <= 0) {
	    printf("%s\n", "Memory Exceeded.");
    } else {
    	if (front) {
        	pos = MAX / 2 - 1 - *p + 1;
        	temp = deq[pos];
        	deq[pos] = 0;
    	} else {
    		pos = MAX / 2 + *p - 1;
    		temp = deq[pos];
    		deq[pos] = 0;
    	}
    	(*p)--;
    }
    return temp;
}

void printArray(int arr[]) {
	int i, isZero = 0;
	printf("%s\n", "Array is:");
	for (i = 0; i < MAX; i++) {
		if (arr[i] != 0) {
			printf("%d ", arr[i]);
			isZero++;
		}
	}	
	if (!isZero) {
		printf("%s", "Array is Zero!");
	}
	printf("\n");
}

/*
#include <stdio.h>
#include <stdlib.h>
#define MEMORY_SIZE 10

void Push(int memory[], int i, int data, int *pf, int *pe);
int Pop(int memory[], int i, int *pos);
void printArray(int arr[]);

int main() {
	int memory[MEMORY_SIZE] = { 0 }, pf = 0, pe = 0;
	
	printArray(memory);
	Push(memory, 0, 1, &pf, &pe);
	printArray(memory);
	Push(memory, 1, 2, &pf, &pe);
	printArray(memory);
	Push(memory, 1, 5, &pf, &pe);
	printArray(memory);
	Pop(memory, 0, &pf);
	printArray(memory);
	Pop(memory, 1, &pe);
	printArray(memory);
	
	int i;
	for (i = 1; i < 7; i++) {
		Push(memory, 0, i, &pf, &pe);
		Push(memory, 1, i, &pf, &pe);
		printArray(memory);
	}
	for(i = 0; i < 5; i++) {
		Pop(memory, 0, &pf);
		Pop(memory, 1, &pe);
		printArray(memory);
	}
	return 0;

}


void Push(int memory[], int i, int data, int *pf, int *pe) {
	int posp, total = *pf + *pe;
	if (total >= MEMORY_SIZE) {
		printf("%s\n", "Memory Size Not Enough!");
	} else {
		if (!i) {
			posp = *pf;
			memory[posp] = data;
			(*pf)++;
		} else {
			posp = MEMORY_SIZE - 1 - *pe;
			memory[posp] = data;
			(*pe)++;
		}
	}
}


int Pop(int memory[], int i, int *pos) {
	int data = 0, posp;
	if (!i) {
		posp = *pos - 1;
	} else {
		posp = MEMORY_SIZE - *pos;
	}
	if (posp >= 0 && posp < MEMORY_SIZE) {
		data = memory[posp];
		memory[posp] = 0;
		(*pos)--;
	}
	return data;
}

void printArray(int arr[]) {
	int i, isZero = 0;
	printf("%s\n", "Array is:");
	for (i = 0; i < MEMORY_SIZE; i++) {
		printf("%d ", arr[i]);
		if (arr[i] != 0) {
			isZero++;
		}
	}	
	printf("\n");
	if (!isZero) {
		printf("%s\n", "Array is Zero!");
	}
}
*/
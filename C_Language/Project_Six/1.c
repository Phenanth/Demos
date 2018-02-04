#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Array 10

void printArray(int line[],int n);

int main(){
	int min_num,i,num[Array],min;
	srand(time(NULL));
	for(i = 0;i<Array;i++){
		num[i] = 10 + rand() % 90;
	}
	printArray(num,Array);
	for(min_num = num [0],min = 0,i = 0;1;i++){
		if(i==10)
			break;
		if(num[i]<min_num){
			min_num = num[i];
			min = i;
		}
	}
	printf("min:%d  which:%d\n", min_num,min + 1);
	return 0;
}
void printArray(int line[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%3d",line[i]);
	printf("\n");
}

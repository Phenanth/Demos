#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Array 11
//the problem:the index returns '-1' continuously,because the example on the text book is the smaller to bigger
//but in the question ,its bigger to smaller,so it should be num > lind[mid] instead of '<'.

void format(int line[],int n);
int isExist(int line[],int n,int num);
void insert(int line[],int n,int num);
void printArray(int line[],int n);

int main(){
	int line[Array]={0},i,num,index;
	srand(time(NULL));
	for(i=0;i<Array-1;i++){
		line[i] = 10 + rand() % 90;
	}
	printf("The random array is:\n");
	printArray(line,Array-1);
	format(line,Array-1);
	printf("The formatted array is:\n");
	printArray(line,Array-1);
	scanf("%d",&num);
	index = isExist(line,Array-1,num);
	if(index==-1){
		insert(line,Array,num);
		printf("Can't find the number %d,New array:\n",num);
		printArray(line,Array);
		printf("\n");
	}else printf("%d 's position:%d\n",num,index);
	return 0;
}
void format(int line[],int n){
	int i,j;
	for(i=0;i < n - 1;i++){
		for(j = 0;j < n-i-1;j++){
			if(line[j]<line[j+1]){
				int temp = line[j];
				line[j] = line[j+1];
				line[j+1] = temp; 
			}
		}
	}
}
int isExist(int line[],int n,int num){
	int right,left,mid;
	left = 0;
	right = n - 1;
	do{
		mid = (left + right) / 2;
		if(num == line[mid])
			return mid;
		else if(num > line[mid])
			right = mid - 1;
		else left = mid + 1;
	}while(left <= right);
	return -1;
}
void insert(int line[],int n,int num){
	line[n-1] = num;
	format(line,Array);
}
void printArray(int line[],int n){
	int i;
	for(i=0;i<n;i++)
	printf("%3d",line[i]);
	printf("\n");
}
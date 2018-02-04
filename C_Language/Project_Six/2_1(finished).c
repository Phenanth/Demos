#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Array 11

void format(int line[],int n);
void generateInt(int line[],int n);
int isExist(int line[],int n,int num);
void insert(int line[],int n,const int num,int index);
void printArray(int line[],int n);

int main(){
	int num,index,integer[Array]={0};
	generateInt(integer,Array-1);
	printArray(integer,Array-1);
	format(integer,Array-1);
	printArray(integer,Array-1);
	printf("Input the number you want to search:");
	scanf("%d",&num);
	index = isExist(integer,Array-1,num);//1-2:0 3:2 4-5:3  6:5 7-8:6 9:8 10-11:9
	if(integer[index] != num){
		insert(integer,Array,num,index);
		printf("Can't find the number %d,The new array is:\n",num);
		printArray(integer,Array);
	}else printf("Find the number %d!,its position is:%d\n",num,index + 1);
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
	return mid;
}
void insert(int line[],int n,const int num,int index){
	int i;
	line[n - 1] = line[n - 2]; 
    for(i = n - 2;i >= 0;i--){
       if(num > line[i]){
            line[i + 1] = line[i];
		}else{
			line[i + 1] = num;
			break;      
       }
    }
    if(num > line[0])
		line [0] = num;
}
void printArray(int line[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%3d",line[i]);
	printf("\n");
}
void generateInt(int line[],int n){
	int i;
	srand(time(NULL));
	for(i = 0; i < n;i++){
		line[i] = (10 + rand() % 90);
	}
}

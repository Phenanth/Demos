/*第2题 30分
从键盘以逗号为分隔符输入10个整数，比如43,5,34,12,7,23,91,69,73,4,将其保存到数组中；
将10个数按从大到小进行排序；
将排序后的结果显示，并将排序后的结果存储到文件 data.txt 中。

录入数据部分采用循环 10为定义好的数字（格式：%d,），并将数字放入数组
使用qsort对数组进行从大到小的排序

老师说还是需要管最后一位的输入
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define FILENAME "data.txt"

void inputData(int numArray[]);
int comp(const void *p,const void *q);
void printData(int numArray[]);

int main(){
	int numArray[SIZE];
	inputData(numArray);
	qsort(numArray,SIZE,sizeof(int),comp);
	printData(numArray);
	return 0;
}
void inputData(int numArray[]){
	int i;
	printf("Input data(Format:num,num,...num):\n");//改过了
	for(i = 0;i < SIZE-1;i++){
		scanf("%d,",&numArray[i]);
	}
	scanf("%d",&numArray[i]);
}
int comp(const void *p,const void *q){
	return *((int *)q) - *((int *)p);
}
void printData(int numArray[]){
	int i;
	FILE *fp;
	fp = fopen(FILENAME,"w");
	if(fp == NULL){
		printf("Can't make the file %s!\n",FILENAME);
		exit(EXIT_FAILURE);
	}
	printf("The num array is:\n");
	for(i = 0;i < SIZE;i++){
		printf("%d ",numArray[i]);
		fprintf(fp, "%d ",numArray[i]);
	}
	printf("\n");
	printf("The file %s has been made!\n",FILENAME);
	fclose(fp);
}


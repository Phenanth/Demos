/*
实验8_1 
题目：
编写程序，使用文本文件方式，创建一个文件。
随机生成 25 个整数并按从小到大的顺序写入到指定文件中，整数之间用一个空格间隔。
然后重新打开文件，依次读出每个整数并显示在屏幕上，显示时要求每行显示5 个整数。

构成：
main函数功能：包括两个功能函数dataSort和dataPrint
dataSort函数功能：从小到大排序后输入到指定文件（8_1file.txt）中，输入到文件后关闭文件。
dataPrint函数功能：再重新打开文件到这个指针（新fp）中，依次读出与显示，最后关闭该文件。
geRN函数功能：产生随机数
comp函数功能：qsort函数所需的排序规则
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 25//随机数个数
#define A 10//随机数下限
#define B 89//随机数上限为89+10
#define H 5//每隔5个换行
#define FILENAME "8_1file.txt"

void dataSort(void);
void dataPrint(void);
int geRN(int a,int b);
int comp(const void *p,const void *q);

int main(){
	dataSort();
	dataPrint();
	return 0;
}
void dataSort(void){
	FILE *fp;
	int array[N],i;
	fp = fopen(FILENAME,"w");
	if(fp == NULL){
		printf("Can't open the file:%s!\n",FILENAME);
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	for(i = 0;i < N; i++)
		array[i] = geRN(A,B);
	qsort(array,N,sizeof(int),comp);
	for(i = 0;i < N; i++){
		fprintf(fp,"%d",array[i]);
		if(i != N - 1)
			fprintf(fp," ");
	}
	fclose(fp);
}
void dataPrint(void){
	FILE *fp;
	int i;
	fp = fopen(FILENAME,"r");
	if(fp == NULL){
		printf("Can't open the file:%s!\n",FILENAME);
		exit(EXIT_FAILURE);
	}
	for(i = 1; i <= N; i++){
		int temp;
		fscanf(fp,"%d",&temp);
		printf("%5d",temp);
		if((i >= H) && (i % H == 0) && (i != N))
			printf("\n");
	}
	fclose(fp);
}
int geRN(int a, int b){
	return (rand() % b + a);
}
int comp(const void *p,const void *q){
	return (*(int *)p) - (*(int *)q);
}

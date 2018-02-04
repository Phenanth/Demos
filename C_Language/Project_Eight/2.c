/*
实验8_2
题目：
编写程序，建立一个学生基本信息结构，包括学号、姓名以及语文、数学、英语 3门课程的成绩，
输入 n 个学生的基本信息，写到文本文件 student.txt 中。
再从文件中取出数据，计算每个学生3门课程的总分和平均分（保留2位小数），并将结果输出至屏幕上。

构成：
writeData函数功能：打开文件，将输入的基本信息fprintf到文件student.txt（FILENAME）中，关闭文件
calData函数功能：打开文件FILENAME，用结构指针每次读一个结构并计算所需数值输到显示器上，直到structpoint到达文件的末尾（NULL/EOF需执行时再看）
				输出结束，关闭文件
可以优化格式
*/
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "student.txt"

typedef struct student{
	char identity[20];
	char name[9];
	int chinese;
	int math;
	int english;
}STUDENT,*STUDENTP;

int writeData(void);
void calData(int n);

int main(){
	int n;
	n = writeData();//n为输入资料的人数，因为下面函数也需要用到 所以作为返回值传回
	calData(n);
	return 0;
}
int writeData(void){
	FILE *fp;
	int i,n;
	STUDENT temp;
	fp = fopen(FILENAME,"w");
	if(fp == NULL){
		printf("Can't open the file:%s!\n",FILENAME);
		exit(EXIT_FAILURE);
	}
	printf("The number of the student is:");
	scanf("%d",&n);
	for(i = 0; i < n;i++){
		scanf("%s%s%d%d%d",temp.identity,temp.name,&temp.chinese,&temp.math,&temp.english);
		fprintf(fp,"%-20s%-9s%-5d%-5d%-5d\n",temp.identity,temp.name,temp.chinese,temp.math,temp.english);
	}
	fclose(fp);
	printf("The file %s had been made.\n",FILENAME);
	return n;
}
void calData(int n){
	FILE *fp;
	int i;
	STUDENT temp;
	STUDENTP p;
	fp = fopen(FILENAME,"r");
	p = &temp;
	for(i = 0;i < n;i++){
		double total,ave;
		fscanf(fp,"%s%s%d%d%d",temp.identity,temp.name,&temp.chinese,&temp.math,&temp.english);
		total = p -> chinese + p -> math + p -> english;
		ave = total / 3;
		printf("Student %9s : total: %3.0lf average: %3.2lf",p->name,total,ave);
		if(i != n - 1)
			printf("\n");
	}
	fclose(fp);
}

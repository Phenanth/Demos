/*
2.编写程序，输入若干个学生的信息（包括学号、姓名和成绩），
输入学号为 0 时输入结束，用单向链表组织输入的学生信息。
定义和调用函数：struct student *createList();  
建立单向链表，返回指向链表头结点的指针。
定义和调用函数：voidprintList(struct student *head, int score); 
根据输入的一个成绩值，将成绩大于等于该值的学生信息输出。

学号由字符串来键入，比较通过字符串比较进行循环
结点内部为学号姓名和成绩和结构（结点）指针（声明结构时做）
每次建立结点时在循环体内放置结构指针t为新建立指针，p为工作指针，tail指向上一个结点
head指向第一个结点不变
输出比其成绩大的由printList函数做，定义工作指针p，每一次比较后向下一个结点移动
根据比较结果决定是否输出此结点内信息
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 21

typedef struct student{
	char no[SIZE];
	char name[13];
	int score;
	struct student *next;
}NODE,*NODEP;

NODE *createList();
void printList(NODEP head,int score);

int main(){
	NODEP head;
	int score;
	head = createList();
	printf("Input the score:");
	scanf("%d",&score);
	printList(head,score);
	return 0;
}
NODE *createList(){
	char no[SIZE],exa[SIZE]={"0"};
	NODEP head = NULL,t,tail;
	FILE *fp;
//	printf("Input the information of the student(s)\n(0 for student number is the symbol of ending):\n");
	fp = fopen("data7_21.txt","r");
	if(fp == NULL){
		printf("Can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fp,"%s",no);
	while(strcmp(no,exa) != 0){
		t = (struct student *)malloc(sizeof(struct student));
		strcpy(t -> no,no);
		fscanf(fp,"%s%d",t -> name,&(t -> score));
		if(head == NULL)
			head = t,tail = t;
		else tail -> next = t;
		tail = t;
		t -> next = NULL;
		fscanf(fp,"%s",no);
	}
	fclose(fp);
	return head;
}
void printList(NODEP head,int score){
	NODEP p = head;
	printf("The information of the student(s):\n");
	while(p != NULL){
		if(p -> score >= score)
			printf("Name:%-13sStudentNumber:%-21sScore:%-4d\n",p->name,p->no,p->score);	
		p = p -> next;
	}
}

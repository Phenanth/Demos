#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 50

typedef struct contact{
	char name[13];
	long birthday;
	char tel[12];
}CON,*PCON;

int num;
void inPutData(PCON person);
int comp(const void *p,const void *q);
void outPutData(PCON person);

int main(){
	CON person[ARRAYSIZE];
	inPutData(person);
	qsort(person,num,sizeof(struct contact),comp);
	outPutData(person);
	return 0;
}
void inPutData(PCON person){
	int i;
	PCON p = person;
	FILE *fp;
	fp = fopen("data7_1.txt","r");
	if(fp == NULL){
		printf("Can't find the file!\n");
		exit(EXIT_FAILURE);
	}
	printf("Input the number of the people:\n");
	scanf("%d",&num);
	for(i = 0; i < num;i++){
		fscanf(fp,"%s%ld%s",p -> name,&(p -> birthday),p -> tel);
		p++;
	}
	fclose(fp);
}
int comp(const void *p,const void *q){
	return (((struct contact *)p) -> birthday - ((struct contact *)q) -> birthday);
}
void outPutData(PCON person){
	int i;
	PCON p = person;
	for(i = 0;i < num;i++){
		printf("%-10s%-15ld%-15s\n",p -> name,p -> birthday,p -> tel);
		p++;
	}
}

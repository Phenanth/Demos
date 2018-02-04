#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define ARRAYSIZE 50
#define FILENAME "1_file.txt"

typedef struct contact{
	char name[9];
	int year;
	int month;
	int day;
	char tel[12];
	int aboutDay;
}CON,*PCON;

int n;
void inPutData(PCON stu);
void sortData(PCON stu);
void outPutData(PCON stu);

int main(){
	CON stu[ARRAYSIZE];
	inPutData(stu);	
	sortData(stu);
	outPutData(stu);
	return 0;
}
void inPutData(PCON stu){
	int i;
	PCON p = stu;
	FILE *fp;
	fp = fopen(FILENAME,"r");
	if(fp == NULL){
		printf("Can't open the file!\n");
		exit(EXIT_FAILURE);
	}
	printf("Input the number of people:\n");
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		fscanf(fp,"%s%d%d%d%s",p -> name,&(p -> year),
							&(p -> month),&(p -> day),
							p -> tel);
		p++;
	}
	fclose(fp);
}
void sortData(PCON stu){
	int i,j;
	CON temp;
	for(i = 0; i < n;i++)
		stu[i].aboutDay = (stu[i].month + (stu[i].year - 1) * 12) * 31 + stu[i].day;
	for(i = 0;i < n - 1;i++){
		for(j = n - 1;j > 0;j--){
			if(stu[j].aboutDay < stu[j - 1].aboutDay){
				temp = stu[j];
				stu[j] = stu[j - 1];
				stu[j - 1] = temp;				
			}
		}
	}
}
void outPutData(PCON stu){
	int i;
	PCON p = stu;
	for(i = 0; i < n;i++){
		printf("%-10s%-6d%-6d%-6d%-15s\n",	p -> name,p -> year,p -> month,
											p -> day,p -> tel);
		p++;
	}
}

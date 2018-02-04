#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define len_Char 100
#define len_Int 27

void calTimesOfAlpha(char str[],int appear[],int length);
void printArray(int line[],int length);
int comp(const void *p,const void *q);

int main(){
	char str[len_Char];
	int appear[len_Int]={0},length;
	printf("Input a string:\n");
	gets(str);
	length = strlen(str);
	qsort(str,length,sizeof(char),comp);
	calTimesOfAlpha(str,appear,length);
	printArray(appear,length);
	return 0;
}
void calTimesOfAlpha(char str[],int appear[],int length){
	int i,j;
	for(j = 0;j < length;j++){
		for(i = 0;i < 26;i++){
			if(str[j]=='A'+i||str[j]=='a'+i)
				appear[i]++;
		}
	}
}
int comp(const void *p,const void *q){
	return strcmp((char *)p , (char *)q);
}
void printArray(int line[],int length){
	int i;
	char ch;
	for(i = 0,ch = 'a'; i < 26;ch++,i++){
		printf("%c has appeared %2d times\n",ch,line[i]);
	}
	printf("\n");
}

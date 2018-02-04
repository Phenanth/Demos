#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
char *strstring(char str1[],char str2[],int index,int length);
int main(){
	char *s = NULL,str1[SIZE],str2[SIZE];
	int index = 0,length = 0;
	printf("Input a string(ended by the enter key),and index,length in order:\n");
	gets(str1);
	scanf("%d%d",&index,&length);
	if(str1 == NULL)
		exit(0);
	else s = strstring(str1,str2,index,length);
	if(s != NULL)
		printf("The picked out string is:%s\n",s);
	else{	printf("Inllegal input!\n");
			puts(s);}
	return 0;
}
char *strstring(char str1[],char str2[],int index,int length){
	char *p = str1,*q = str2;
	if(index + length > (signed)strlen(str1)||index < 0)
		return NULL;
	for(p += index;p < str1 + index + length;p++,q++)
		*q = *p;
	*q = '\0';
	return str2;
}

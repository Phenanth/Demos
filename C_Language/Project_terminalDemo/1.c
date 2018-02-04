/*
编写字符串函数,要求如下：
函数名称为 char * strstr(char * s, int index, int length)
函数功能为从字符串s中第index处开始取length长度的字符返回

未完成 存在输入的字符串永远为空 无法正常输入index length问题
问题都解决了 完成版是1_1.c 但是我还是不知道这个版本哪里有问题嘻嘻
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
char *strstring(char s[],char str[],int index,int length);
int main(){
	char *s,stro[SIZE]=NULL,strp[SIZE]=NULL;
	int index,length;
	printf("Input the origin string,index,length in order:");
	scanf("%d%d",&index,&length);
	getchar();
	gets(stro);
	if(stro!=NULL)
		s = strstring(stro,strp,index,length);
	else exit(0);
	if(s != NULL)
		printf("The picked out string is:%s\n",s);
	else puts(s);
	return 0;
}
char* strstring(char s[],char str[],int index,int length){
	char *p = s + index，*q = str;
	//int i=0;
	if(index + length > (signed)strlen(s))
		return str;//问题在这下面
	for(;p < s + index + length - 1;i++)
		str[i] = p[i];
	str[i] = '\0';
	return q;
}

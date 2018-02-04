#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 20

int isAnagram(char *str1,char *str2);
int comp(const void *p,const void *q);

int main(){
	char str1[length],str2[length];
	printf("Input two strings:\n");
	scanf("%s",str1);
	scanf("%s",str2);
	if(isAnagram(str1,str2)==0)
		printf("Yes\n");
	else printf("No\n");
	return 0;
}

int isAnagram(char *str1,char *str2){
	int len1,len2,i,key = 0;
	len1 = strlen(str1);
	len2 = strlen(str2);
	if(len1 != len2)
		key++;
	qsort(str1,len1,sizeof(char),comp);
	qsort(str2,len2,sizeof(char),comp);
	for(i = 0;i < len1;i++){
		if(str1[i]!=str2[i])
			key++;
	}
	return key;
}
int comp(const void *p,const void *q){
	return strcmp((char *)p , (char *)q);
}

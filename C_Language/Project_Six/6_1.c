#include <stdio.h>

int isAnagram(char *str1,char *str2,int *count1,int *count2);
int main(){
	int str1,str2,count1[128],count2[128];
	gets(str1);
	gets(str2);
	if(isAnagram(str1,str2,count1,count2))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}


int isAnagram(char *str1,char *str2,int *count1,int *count2){
	int i = 0;
	while(str1[i]!='\0') count1[(int)str[i++]]++;
	i = 0;
	while(str2[i]!='\0') count2[(int)str[i++]]++;
	for(i = 0;i < 128;i++)
		if(count1[i]!=count2)	return 0;
	return 1;
}
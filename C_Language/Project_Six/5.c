#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define string_len 30

int isParraString(char *str,int len);

int main(){
	int length;
	char str[string_len];
	printf("Input a string:\n");
	gets(str);
	length = strlen(str);
	if(isParraString(str,length)==1)
		printf("Is a parral string!\n");
	else printf("Isn't a parral string!\n");
	return 0;
}
int isParraString(char *str,int len){
	int left,right;
	left = 0, right = len - 1;
	while(left <= right){
		if(str[left] != str[right])
			return -1;
		left++,right--;
	}
	return 1;
}

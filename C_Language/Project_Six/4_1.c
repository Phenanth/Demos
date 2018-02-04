#include <stdio.h>
#include <string.h>
#define LENGTH 100
int main(){
	char str[LENGTH + 1]
	int i,j.count[128]={0};
	gets(str);
	calAlphaP(str,count);
	printArray(count);
}

void calAlphaP(char *str,int *count){
	int i; 
	while(str[i]!='\0') count[(int)str[i++]]++;

}
void calAlphaP(int *count){
	int i,j;
	for(i =;i < 26;i++){
		j = count['A' + i] + count['a' + i];
		if(j != 0)
			printf("%c had appeared %d times!\n",'count[i]',j);
	}
}
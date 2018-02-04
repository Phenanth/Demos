/*y
<h3>从键盘输入10个整数，将其中的偶数显示出来。</h3>
*/
#include <stdio.h>
#define SIZE 10
void printO(int *num);
int main(){
	int num[SIZE]={0},i=0;
	while(i < SIZE)	
		scanf("%d",&num[i++]);
	printO(num);
	return 0;
}
void printO(int *num){
	int i=0;
	while(i++ < SIZE){
		if(num[i] % 2 == 0)
			printf("%d ",num[i]);
		i++;
	}		
	printf("\n");
}

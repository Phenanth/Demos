#include <stdio.h>
#include <string.h>

int isPrime(int num);

int main(){
	int i,count=0,a;
	char ss[10];
	for(i=6;i<=100;i+=2)
		for(a=3;a<=i;a+=2){
			if(isPrime(a)&&isPrime(i-a)){
				sprintf(ss, "%d=%d+%d", i, a, i - a);
				printf("%-9s", ss);
				count++;
				if(count % 5 == 0)
				printf("\n");
				break;			
			}

		}
	return 0;
}

int isPrime(int num){
	int i;
	if(num%2==0)
		return 0;
	for(i=3;i<=num;i++)
		if(num%i==0)
			break;
	if(i==num)
		return 1;
	else return 0;
}

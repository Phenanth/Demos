#include <stdio.h>

int isPrime(int number);

int main(){
	int a, b, c, count=0;
	for(a=6;a<=100;a+=2)
		for(b=3;b<=a;b+=2){
			c=a-b;
			if(count%5==0&&count!=0)
				printf("\n");
			if(isPrime(b)&&isPrime(c)){
				printf("%d=%d+%-6d",a,b,c);
				count++;
				break;
			}
			
		}
		return 0;

}

int isPrime(int number){
	int i;
	for(i=2;i<=number;i++){
		if(number%i==0)
			break;
	}

	if(number==i)
		return 1;
	else return 0;

}

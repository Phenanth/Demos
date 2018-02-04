#include <stdio.h>

int isPrime(int number);

int main(){
	int a, b, c, count;
	for(a=6;a<=100;a+=2)
		for(b=3;b<=a;b+=2){
			c=a-b;
			for(count=0;count<=5;)
				if(isPrime(b)&&isPrime(c)){
					printf("%d=%d+%-6d",a,b,c);
					count++;
					continue;
				}
			
			printf("\n");
			if(c==1)
				break;
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

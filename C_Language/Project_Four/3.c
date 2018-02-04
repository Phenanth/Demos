#include <stdio.h>
#include <math.h>

int isPrime(int number);

int main(){
	int a,
		b,
		c,
		count=0;
	for(a=6;a<=100;a+=2){
		//for(b=3,c=a-b;b<=a;b+=2)
				do{
			for(b=3,c=a-b;b<=a;b+=2)
				if(b!=1&&c!=1){
				printf("%6d=%d+%d",a,b,c);			
				count++;
				}
				if(isPrime(b)&&isPrime(c))
					break;
					
			}while(isPrime(b)&&isPrime(c))
			//count++;
			
			if(count%5==0)
				printf("\n");
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

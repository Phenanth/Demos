#include <stdio.h>

long sequence(int n);

int main(){
	int count=0,n;
	for(n=1;n<=20;n+=1){
		printf("%6ld", sequence(n));
		count++;
		if(count%5==0)
			printf("\n");
	}
	
	return 0;
}

long sequence(int n){
	int y1,y2,y3,y,count=0,;
	long value;

	y1=0,y2=1,y3=2;
		
	if(n==1) y=0;
	if(n==2) y=1;
	if(n==3) y=2;

	while((count+3)<n){
		y=y1+y2+y3;
		y1=y2,y2=y3,y3=y;
		count++;
	};
	
	value=(long)y;		
	return value;
}

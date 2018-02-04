#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverse(int number){	
	int newone=0,
		last,
		count=0,
		count2,
		count3,
		number1,
		number2,
		middle,
		time;
	
	number1 = abs(number);
	number2 = abs(number);
		do{number1 = number1 / 10;
			count++;
		}while(number1!=0);
		count3 = count;
		for(time=1;time<=count3;time++){
			last = number2 % 10;
			number2 /= 10;
			count--;
			for(count2=1,middle=1;count2<=count;count2++)
				middle*=10;
			newone = newone + last * middle;
	}
	if(number<0)
		newone = 0 - newone;	
	return newone;	
}

int main(){
	int number,
		new1;
	//char ch;
	
	while(1){
	printf("please input a integer:");
	scanf("%d",&number);
	new1 = reverse(number);
	printf("the reverse number is:%d\n",new1);
	/*printf("if you want to reverse another number?(Y/N)\n");
	while((ch=getchar())=='N'||(ch=getchar())=='n')  //n/N
		break;*/
	}
	
	
	return 0;
}


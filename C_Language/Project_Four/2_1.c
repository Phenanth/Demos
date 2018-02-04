#include <stdio.h>
#include <stdlib.h>

int reverse(int number);

int main(){
	int number,new1;
	while(1){
	printf("please input a integer(not ended by zero):");
	scanf("%d",&number);
	new1 = reverse(number);
	printf("the reverse number is:%d\n",new1);
	}

	return 0;
}

int reverse(int number){
	int number1,new2=0,middle;
	number1 = abs(number);
	while(number1!=0){
		middle = number1 % 10;
		new2 = new2 * 10 + middle;
		number1 = number1 / 10;
	};
	if(number<0)
		new2 = -new2;

	return new2;

}

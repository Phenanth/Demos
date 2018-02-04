#include <stdio.h>

int main(){
	int number1,middle,new2;
	number1 = 1234;
	while(number1!=0){
		middle = number1 % 10;
		new2 = new2 * 10 + middle;
		number1 = number1 / 10；
		printf("new=%d\n", new2);
	}
	return 0;
}

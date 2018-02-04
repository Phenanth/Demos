#include <stdio.h>
//上机实验五 将一个三位数（个位数不为零）按逆序转换为新的整数后输出

int main(void) {
	
	int num1, a, b, c, num2;//假设number abc
	printf("please input a three-digit number(It's not ended by 0):\n");
	scanf("%d",&num1);
	c = num1 % 10;
	b = (num1 / 10) % 10;
	a = (num1 / 10 / 10) % 10;
	num2 = c * 100 + b * 10 + a;
	printf("the new number is:%d\n",num2);

	return 0;
} 

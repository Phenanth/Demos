#include <stdio.h>
//上机实验二 输入两个整数，计算并输出这两个整数的和、差、积、商、余数

int main(void) {

	int num1, num2 ;
	printf("please input integer one:");
	scanf("%d",&num1);
	printf("please input integer two:");
	scanf("%d",&num2);
	printf("%d+%d=%d\n",num1,num2,num1 + num2);//求和
	printf("%d-%d=%d\n",num1,num2,num1 - num2);//求差
	printf("%d*%d=%d\n",num1,num2,num1 * num2);//求积
	printf("%d/%d=%f\n",num1,num2,num1 * 1.0 / num2);//求商
	printf("%d%%%d=%d\n",num1,num2,num1 % num2);//取余


	return 0;

}

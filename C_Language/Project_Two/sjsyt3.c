#include <stdio.h>
//上机实验三 输入两个整数，计算并输出这两个整数的平均值、最小值和最大值

int main() {
	
	int num1, num2, max, min;
	double sum, ave;
	printf("please input integer one:");//输入整数1
	scanf("%d",&num1);
	printf("please input integer two:");//输入整数2
	scanf("%d",&num2);
	sum = num1 + num2;//求和
	printf("%d+%d=%lf\n",num1,num2,sum);
	ave = sum / 2;//平均数
	printf("the two integers' average is:%.2lf\n",ave);
	max = (num1 > num2)?num1:num2;//取大
	min = (num1 > num2)?num2:num1;//取小
	printf("In the two integers, the max is:%d\n",max);
	printf("In the two integers, the min is:%d\n",min);

	return 0;
}

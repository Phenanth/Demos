/*
第1题 30分
用户输入一天之内的2个时间，输入格式为"hh:mm"（且满足hh：00 ~ 23，mm: 00~59），
但时间数据的输入不一定满足先后次序（即可能是10:24、03:45，也可能是03：45、10:24）。
编写程序计算这2个时间的差，并且按示例格式输入数据和打印结果。

[ 示例 ]

用户数据输入：
10:24↲
03:45↲
程序输出结果：
the sub time is: 6:39

写一个结构放入时间的时和分，将该结构传入计算时间的函数并返回该结构（三号）
计算时间的函数中应先判断输入的两个结构的时间先后再做加减法

另：可以把数据全部简化为分钟，做完减法后再进行时间表示方法的换算
上述由函数完成
*/
#include <stdio.h>
#define MINUTES 60

int calTime(int time1,int time2);

int main(){
	int hour1=0,minute1=0,hour2=0,minute2=0,hour3,minute3;
	do{
		printf("Please input two time:(format:hh:mm)\n");
		scanf("%d:%d",&hour1,&minute1);
		scanf("%d:%d",&hour2,&minute2);
	}while(hour1<0||hour2<0||hour1>23||hour2>23||minute1<0||minute2<0||minute1>59||minute2>59);
	int time1,time2,time3;
	time1 = hour1 * MINUTES + minute1;
	time2 = hour2 * MINUTES + minute2;
	time3 = calTime(time1,time2);
	hour3 = time3 / MINUTES;
	minute3 = time3 % MINUTES;
	printf("The sub time is:%2d:%2d",hour3,minute3);
	return 0;
}
int calTime(int time1,int time2){
	if(time1 == time2)
		return 0;
	else if(time1 > time2)
		return time1 - time2;
	else return time2 - time1;
}


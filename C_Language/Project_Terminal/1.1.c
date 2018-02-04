/*
*/
#include <stdio.h>
#define MINUTES 60

int calTime(int time1,int time2);

int main(){
	int hour1,minute1,hour2,minute2,hour3,minute3;
	do{
		printf("Please input two time:(format:hh mm)\n");
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


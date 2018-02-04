#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializedSeed(void);
int generateRandomNumber(int a,int b);
int computeXXS(char level);
char changeSign(int c);

int main(){
	int time_s, time_e,grade;
	char level;
	time_s = time((time_t*)NULL);
	printf("please choose the level(easy or normal(e/n)):");	
	scanf("%c",&level);
	grade = computeXXS(level);
	time_e = time((time_t*)NULL);
	printf("You have finished 20 questions!\n");
	printf("Your grade is:%d\nIt has been %d sec during your calculation.\n",grade,time_e - time_s);

	return 0;

}

void initializedSeed(void){
	srand(time(NULL));
}

int generateRandomNumber(int a,int b){
	return a + rand() % (b - a + 1);
}

int computeXXS(char level){
	int count,sign_number,num1,num2,answer,grade=100,answer1;
	char sign;
	for(count=1;count<=20;count++){
		initializedSeed();
		sign_number = generateRandomNumber(1,4);
		sign = changeSign(sign_number);
		if(level=='e'||level=='E'){
		num1 = generateRandomNumber(1,9);
		num2 = generateRandomNumber(1,9);}
		else{
			num1 = generateRandomNumber(10,99);
			num2 = generateRandomNumber(10,99);
		}
		switch(sign_number){
		case 1: answer1 = num1 + num2; break;
		case 2: answer1 = num1 - num2; break;
		case 3: answer1 = num1 * num2; break;
		case 4: do{
				if(level=='e'||level=='E'){
					num1 = generateRandomNumber(1,9);
					num2 = generateRandomNumber(1,9);
					}
				else{
					num1 = generateRandomNumber(10,99);
					num2 = generateRandomNumber(10,99);
					}
				answer1 = num1 / num2;
				}while((num1 % num2)!=0||num2==1||num1==num2);break;
		}
		printf("Question%2d: %d %c %d = ",count,num1,sign,num2);
		scanf("%d",&answer);
		if(answer != answer1)
			grade -= 5;
	}
	return grade;
}

char changeSign(int c){
	char sign;

	switch(c){
		case 1:sign = '+'; break;
		case 2:sign = '-'; break;
		case 3:sign = '*'; break;
		case 4:sign = '/'; break;
	}

	return sign;

}

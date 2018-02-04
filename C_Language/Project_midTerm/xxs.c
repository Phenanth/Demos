#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializedSeed(void);
int generateRandomNumber(int a,int b);
void generateExercise(void);
void getNums(void);
void changeSign(void);
void doExercise(void);

int x,y,level,a,b,numberOfExercise,i,i1,time_s,time_e,answer,result;
double grade_per_question,grade=0;
char operatorChar,n_y;

int main(){
	getNums();
	time_s = time((time_t*)NULL);
	for(i=1;i<=numberOfExercise;){
		initializedSeed();
		generateExercise();
		doExercise();
		if(answer==-1&&(n_y=='Y'||n_y=='y')){
			printf("You quitted the test!\n");
			break;
		}
		i++;
	}
	time_e = time((time_t*)NULL);
	printf("\n******You've completed your test!******\n\nThe level is %d\nYou've finished %d questions",level,i - 1);
	printf("\nYour grade is: %d points\nThe time during the calculation is: %d seconds\n",(int)grade,time_e - time_s);
	return 0;
}

void getNums(){
	printf("----------ARITHMATIC TEST FOR PRIMARY SCHOOL STUDENT----------\n\n!!CAUTION:You have 3 chances for each question.\n!!CAUTION:But the point will be lesser and lesser if you make too much mistakes.");
	printf("\n!!CAUTION:You also can leave the test by inputing '-1' at the first attempt of any question.\n\n");
	do{
	printf("What level do you want to choose?(1/2/3):");
	scanf("%d",&level);
	if(level!=1&&level!=2&&level!=3)
		printf("Please input number that is between 1-3!\n");
	}while(level!=1&&level!=2&&level!=3);
	do{
	printf("How many questions do you want to have?(1-100):");
	scanf("%d",&numberOfExercise);
	if(numberOfExercise<=0||numberOfExercise>100)
		printf("Please input number between 1-100!\n");
	}while(numberOfExercise<=0||numberOfExercise>100);
	grade_per_question = 100 / numberOfExercise;//grade per question.
	switch(level){
		case 1 : a = 1; b = 9;break;
		case 2 : a = 10; b = 39; break;
		case 3 : a = 40; b = 99;break;
	}
	printf("\n******The test has started!******\n\n");
}

void initializedSeed(void){
	srand(time(NULL));
}

int generateRandomNumber(int a,int b){
	return a + rand() % (b - a + 1);
}

void generateExercise(void){
	changeSign();
	do{
	x = generateRandomNumber(a,b);
	y = generateRandomNumber(a,b);
	}while((operatorChar == '/' && x % y != 0)||x - y <= 0||x / y == x);
	if(operatorChar=='+')
		result = x + y;
	else if(operatorChar=='-')
		result = x - y;
	else if(operatorChar=='*')
		result = x * y;
	else result = x / y;
}

void changeSign(void){
	switch(generateRandomNumber(1,4)){
		case 1:operatorChar = '+';break;
		case 2:operatorChar = '-';break;
		case 3:operatorChar = '*';break;
		case 4:operatorChar = '/';break;
			}
}

void doExercise(void){
	for(i1=1;i1<=3;i1++){
		if(answer!=-1||n_y=='N'||n_y=='n')
			printf("Question%3d : %d %c %d = ",i,x,operatorChar,y);
		scanf("%d",&answer);
		if(answer==-1){
			if(i1<=1)
				printf("Do you want to quit the arithmatic test?(Y/N)");
			scanf("%c",&n_y);
			if(n_y=='Y'||n_y=='y')
				break;
			if(n_y=='N'||n_y=='n'){
				i1 -= 2;
				continue;
			}
			}
		else if(answer!=result&&i1==3)
			printf("The answer is still wrong!\n");
		else if(answer==result)
			break;
		else {printf("The answer's wrong!You have %d more chance(s) to correct your answer!\n",3-i1);
			continue;}
	}
	if(i1==1&&answer==result)
		grade = grade + grade_per_question;
	else if(i1==2&&answer==result)
		grade = grade + 0.7 * grade_per_question;
	else if(i1==3&&answer==result)
		grade = grade + 0.4 * grade_per_question;
	else grade = grade;
}

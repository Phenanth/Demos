#include <stdio.h>

int main(){
	int grade, c, count=0;
	printf("please input student's grade:" );
	scanf("%d",&grade);
	
	do{
		
		c = grade / 10;
		
		{if((grade<0)||(grade>100))
		c++;
		else
		switch(c){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		printf("this student's class is:E\n");
		break;
		case 6:
		printf("this student's class is:D\n");
		break;
		case 7:
		printf("this student's class is:C\n");
		break;
		case 8:
		printf("this student's class is:B\n");
		break;
		case 9 :
		case 10:
		printf("this student's class is:A\n");
		break;

		}}
	while(count=0)
		

	return 0;

}

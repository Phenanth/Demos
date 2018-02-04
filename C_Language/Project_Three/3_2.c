#include <stdio.h>

int main(){
	int grade, c, count;
	//char yes_or_no;
	
	do{
		printf("please input student's grade:" );
		scanf("%d",&grade);
		
		c = grade / 10;
		
		if((grade<0)||(grade>100)){
			count++;
			printf("please input a number between 1 and 100\n");}
		}while(count!=0);
			
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
		}
		
		
		
		/*printf("Do you want to input another student's grade?:Y/N\n");
		scanf("%c",&yes_or_no);
		
		if(yes_or_no==89||yes_or_no==121)
			continue;
		if(yes_or_no==78||yes_or_no==110)
				break;
		*/
		
	
	

	return 0;

}

#include <stdio.h>

int main(){
	int grade, c;
	
	do{
		printf("please input student's grade:" );
		scanf("%d",&grade);
				
		if((grade<0)||(grade>100))
			printf("please input a number between 1 and 100\n");
					
		}while((grade<0)||(grade>100));
			
			c = grade / 10;
						
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
			
		
	

	return 0;

}

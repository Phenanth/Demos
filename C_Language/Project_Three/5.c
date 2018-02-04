#include <stdio.h>
//the Enter key is not included in a else character.

int main(){
	double char_count = 0, num_count = 0, else_count = 0;
	char character;
	printf("please input some characters you want to count (ended by Enter key):\n");
	do{
		scanf("%c",&charac、ter);
		if((character>=48)&&(character<=57))
			num_count++;
		else{if(((character>=65)&&(character<=90))||((character>=97)&&(character<=122)))
				char_count++;
			else else_count++;
				
			
		};	
		
	}while(character!='\n');

	printf("the number of the numbers is:%.0lf\n",num_count);
	printf("the number of characters is:%.0lf\n",char_count);
	printf("the number of the else is:%.0lf\n",else_count-1);

	return 0;


}

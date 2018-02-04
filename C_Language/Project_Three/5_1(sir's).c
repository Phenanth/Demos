#include <stdio.h>

int main(void){

	int char_count = 0,
		num_count = 0,
		else_count = 0;
	char ch;
	
	while((ch=getchar())!='\n'){
		if(isalpha(ch)) char_count++;
		else if(isdigit(ch)) num_count++;
			else else_count++;

	}

	printf("char:%d,number:%d,else:%d",char_count,num_count,else_count);

	return 0;
}

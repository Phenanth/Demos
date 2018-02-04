#include <stdio.h>

int main(){
	double count=1, n=1, e;

	printf("e=1+1/1!+1/2!+...,when the last term is smaller than 10^-6,how many terms had been added up?\n");
	
	for(e=1;n>=1e-6;count++){

		n = n / count;
		e = e + n;

		/*n = count * n; 'cus divide  is better than multiplication.
		e = e + 1 / n;*/
	}
	
	//the below lines are 'while' type of circulation, don't mind them.
	/*do{
		n = n / count;
		e = e + n;
		count++;

	}while(n>= 1e-6);*/

	printf("the 'e' is: %lf,it has been %.0lf terms during the calculation.\n",e,count);

	return 0;



}

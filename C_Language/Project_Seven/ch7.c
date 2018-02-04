#include <stdio.h>

int main(){
	char ch = 'U';
//	int b = 128;
//	int c = 230;
//	ch--;//1

	{
		ch |= 127;
	}//2

/*
	{
		ch ^= b;
	}//3
*/
/*
	{
		ch ^= c;
		}
*/
	printf("%x\n",ch);
	return 0;

}

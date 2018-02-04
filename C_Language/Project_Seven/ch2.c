#include <stdio.h>
int main(){
	struct abc{
		unsigned int a:1;
		unsigned int b:3;
		unsigned int c:4;
	}bit,*pBit;
	bit.a = 1;
	bit.b = 7;
	bit.c = 15;
	pBit = &bit;
	pBit -> a = 0;
	pBit -> b &= 3;
	pBit -> c|= 1;
	printf("%d,%d,%d\n",pBit->a,pBit->b,pBit->c);

	return 0;
}

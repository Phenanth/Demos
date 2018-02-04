//1
/*3#2
2#3
*/

#include <stdio.h>

void fun(int x, int y){
	x = x + y;
	y = x - y;
	x = x - y;
	printf("%d#%d\n",x,y );

}

int main(){
	int x = 2, y = 3;
	fun(x,y);
	printf("%d#%d\n",x,y );
	return 0;

}

//3

#include <stdio.h>

int a,b;
void fun(){
	a=100;
	b=200;

}

int main(){
	int a=5,b=7;
	fun();
	printf("%d#%d\n",a,b );
	return 0;
}

//5

#include <stdio.h>

int b =40;
void p(){
	int a=5;
	static int b=5;
	++a;
	++b;
	printf("%d#%d\n", a,b);

}

int main(){
	p();
	p();
	return 0;
}

//7 修改过后 没run过
#include <stdio.h>
int maxCommonFactor(int a, int b);//此处加上分号
int main(){
	int a, b, x;
	printf("Input a,b:");
	scanf("%d%d",&a,&b);//此处加上地址符*2
	x=maxCommonFactor(a,b);
	printf("maxCommonFactor=%d\n",x );
	return 0;//此句为后来加上的
}

int maxCommonFactor(int a, int b)//此处删去分号
{
	int r;
	do{
		r = a % b;
		a = b;
		b = r;

	}while(r!=0);//while后加上分号
	return a;
}
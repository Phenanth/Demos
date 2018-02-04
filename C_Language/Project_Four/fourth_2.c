//2
#include <stdio.h>

int f(int n){
	if(n==1)
		return 1;
	else return n+f(n-1);
}

int main(){
	printf("%d\n",f(5) );
	return 0;
}

//4
#include <stdio.h>
int a=3;
int main(){
	int s=0;
	{
		int a=5;
		s+=a++;
	}
	s+=a++;
	printf("%d\n",s );
	return 0;
}

//6

#include <stdio.h>
#define N 10
void f(void);

int main(){
	f();
	#ifdef N
	#undef N
	#endif
	return 0;
}

void f(){
	#if defined(N)
	printf("N is%d\n",N );
	#else
	printf("N is undefined\n");
	#endif
}

//8 老师说可以先不改语法以外的错误 不过都改过了
#include <stdio.h>
unsigned long factorial(unsigned int number);
int main(){
	unsigned int n, k;
	double c;
	do{
		printf("Please input n,k:");
		scanf("%d%d",&n,&k);		
	}while(n<k);//n>=k→n<k
	c=(double)factorial(n)/(factorial(k)*factorial(n-k));//加上除号下部分的括号
	printf("c=%lf\n",c );//f→lf
	return 0;//后加上
}
unsigned long factorial(unsigned int x){
	unsigned long i, result=1;//加定义为1
	for(i=1;i<=x;++i)//i=2→i=1
		result*=i;
	return result;
}
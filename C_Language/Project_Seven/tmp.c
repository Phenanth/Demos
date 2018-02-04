#include <stdio.h>

typedef struct point{
	int x;
	int y;
}POINT,*POINTP;
int main(){
	POINT s[2]={{1,2},{3,4}};
	POINTP p = s;
	//printf("++p->x:%d\n",++p->x);//1
	//printf("(++p)->x:%d\n",(++p)->x);//2
	return 0;
}

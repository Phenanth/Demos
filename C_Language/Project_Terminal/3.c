/*
第3题 40分
使用结构定义平面的点结构类型struct point，
编写函数 int triangleType(struct point *p1, struct point *p2, struct point *p3) 判断以下情况：

三点不能构成三角形，函数返回0
三点能构成三角形，返回三角形的形状（普通返回1、等腰返回2、等边返回3）
在main函数中输入三个点的坐标数据，检验该函数的正确性。

思路：函数计算给定三个点的距离，判断三个点各满足什么类型（每个边长满足的三角形情况），
返回值顺序按照题目所给的来

修改：计算长度改为函数计算
	判断三角形是否合法的语句改进
	改进结构可以根据double算
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSLON 1e-3
/*
typedef struct point{
	int x;
	int y;
}POINT;
*/
typedef struct point{
	double x;
	double y;
}POINT;

int triangleType(struct point *p1, struct point *p2, struct point *p3);
double lentgh(double x1,double x2,double y1,double y2);

int main(){
	POINT p1,p2,p3;
	int index;
	printf("Input three points:(Format:x1 y1 x2 y2 x3 y3)\n");
	scanf("%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y);
	index = triangleType(&p1,&p2,&p3);
	if(index == 0)
		printf("Can't make a triangle!\n");
	if(index == 1)
		printf("Normal triangle!\n");
	if(index == 2)
		printf("A triangle has two equal lines!\n");
	if(index == 3)
		printf("A triangle has three equal lines!\n");
	return 0;
}

int triangleType(struct point *p1, struct point *p2, struct point *p3){
	double d1,d2,d3;
//	double k,b;
/*
	if(p2->x != p1->x)
		k = (p2->y - p1->y) / (p2->x - p1->x);
	else k = 0;
	b = p1->y - k*(p1->x);
*/
	d1 = lentgh(p1->x,p2->x,p1->y,p2->y);
	d2 = lentgh(p1->x,p3->x,p1->y,p3->y);
	d3 = lentgh(p3->x,p2->x,p3->y,p2->y);
/*
	if(d1 + d2 < d3||d2 + d3 < d1||d1 + d3 < d2||(p3->y == k*(p3->x) + b)||(p1->x==p2->x&&p1->x==p3->x&&p2->x==p3->x))//不成为三角形：三边长度不合法，三点成同一直线。
		return 0;
	else if((p1->x==p2->x)&&(p1->y==p2->y)||(p1->x==p3->x)&&(p1->y==p3->y)||(p2->x==p3->x)&&(p2->y==p3->y))//任意两点相等也不成立
		return 0;
	else if((d1==d2 && d1!=d3 && d2!=d3)||(d1==d3 && d1!=d2 && d3!=d2)||(d2==d3 && d1!=d2 && d1!=d3))
		return 2;
	else if(d1==d2 && d1==d3 && d2==d3)//等边三角形测试时若给整型的点，将无法达到equal。所以真正判断时应当作差值小于绝对值处理。
		return 3;
	else return 1;
*/
	if(d1 + d2 <= d3||d2 + d3 <= d1||d1 + d3 <=d2)
		return 0;
	else if(fabs(d1-d2)<EPSLON && fabs(d2-d3)<EPSLON && fabs(d1-d3)<EPSLON)
		return 3;
	else if(fabs(d1-d2)<EPSLON || fabs(d2-d3)<EPSLON || fabs(d1-d3)<EPSLON)
		return 2;
	else return 1;
}

double lentgh(double x1,double x2,double y1,double y2){
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
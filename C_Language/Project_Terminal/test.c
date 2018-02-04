#include <stdio.h>
#include <math.h>
typedef struct point{
	int x;
	int y;
}POINT;

int triangleType(struct point *p1, struct point *p2, struct point *p3);

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
	double k,b;
	if(p2->x != p1->x)
		k = (p2->y - p1->y) / (p2->x - p1->x);
	else k = 0;
	b = p1->y - k*(p1->x);
	d1 = sqrt((p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
	d2 = sqrt((p1->x - p3->x)*(p1->x - p3->x) + (p1->y - p3->y)*(p1->y - p3->y));
	d3 = sqrt((p2->x - p3->x)*(p2->x - p3->x) + (p2->y - p3->y)*(p2->y - p3->y));
	if(d1 + d2 < d3||d2 + d3 < d1||d1 + d3 < d2||(p3->y == k*(p3->x) + b)||(p1->x==p2->x&&p1->x==p3->x&&p2->x==p3->x))//不成为三角形：三边长度不合法，三点成同一直线。
		return 0;
	else if((p1->x==p2->x)&&(p1->y==p2->y)||(p1->x==p3->x)&&(p1->y==p3->y)||(p2->x==p3->x)&&(p2->y==p3->y))//任意两点相等也不成立
		return 0;
	else if((d1==d2 && d1!=d3 && d2!=d3)||(d1==d3 && d1!=d2 && d3!=d2)||(d2==d3 && d1!=d2 && d1!=d3))
		return 2;
	else if(d1==d2 && d1==d3 && d2==d3)//等边三角形测试时若给整型的点，将无法达到equal。所以真正判断时应当作差值小于绝对值处理。
		return 3;
	else return 1;
}

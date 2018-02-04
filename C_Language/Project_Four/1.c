#include <stdio.h>
#include <math.h>
//#define N

double computeArea(double a, double b , double c , double d, double alpha){
	double p1,area,alpha2;
	alpha2 = 1 / 2.0 * alpha / 180 * 3.14159;
	p1 = 1 / 2.0 * ( a + b + c + d );
	area = sqrt((p1 - a) * (p1 - b) * (p1 - c) * (p1 - d) - a * b * c * d * cos(alpha2) * cos(alpha2));
	return area;
}

int main(){
	double a, b, c, d, alpha,area;
	#ifndef N
	a = 3, b = 4, c = 5, d = 5, alpha = 145;
	#endif
	#ifdef N
	printf("please input the four lines and the opppsite anchors of the quadrilateral: ");
	scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&alpha);
	#endif
	area = computeArea(a,b,c,d,alpha);
	printf("the area of the quadrilateral is:%lf\n",area);

	return 0;

}

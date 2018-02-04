#include <stdio.h>
#include <math.h>

int main(){
    double x, y;

    printf("please input a number:");
    scanf("%lf",&x);

    if(x<0)
        y = x * x;
    if((0<=x)&&(x<9))
        y = sqrt(x);
    if(x>=9)
        y = x - 6;
    
    printf("y=%.2lf\n",y);

    return 0;


}

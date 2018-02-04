#include <stdio.h>

int main(){
    double weight,fee1,fee2,fee;
    
    printf("please input the weight of your baggage:");
    scanf("%lf",&weight);
    
    fee1=50 * 0.25;
    fee2=fee1+ 50*0.35;
    
    if(weight<=50)
    fee=weight *0.25;
    if((weight>50)&&(weight<=100))
    fee=fee1+(weight-50)*0.35;
    if(weight>100)
    fee=fee2+(weight-100)*0.45;
    
    printf("%.2lf\n",fee);
    return 0;
    
    
    
    
}

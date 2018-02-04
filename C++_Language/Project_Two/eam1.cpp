#include <iostream>
using namespace std;

int main(){
int *p,*q,u,v;
p=&u;
q=&v;
u=3,v=5;
cout << *p + *q;
return 0;
}

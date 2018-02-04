#include <iostream>
using namespace std;
int fun(int n){
	if(n == 1)
		return 1;
	else return n + fun(n-1);
}

int main(){
	int num,i,result = 0;
	cin >> num;
	for(i = 1;i <= num;i++)
		result += fun(i);
	cout << result;
	return 0;
}

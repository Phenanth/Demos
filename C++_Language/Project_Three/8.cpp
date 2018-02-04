#include <iostream>
using namespace std;

int main(){
	int n, i;
	double sum = 0;
	cin >> n;
	for(i = 1;i <= 2*n-1; i += 2)
		sum += 1.0 / i;
	cout << sum;
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	const double STOP = 0.000001;
	double num, x1, x2;
	cin >> num;
	x1 = num;
	x2 = 1 / 3.0 * (2 * x1 + num / (x1 * x1));
	while(abs(x2 - x1) >= STOP){
		x1 = x2;
		x2 = 1 / 3.0 * (2 * x1 + num / (x1 * x1));
	}
	if(num == 0)
		cout << 0;
	else cout << x2;
	return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double count = 1, n = 1, e, num;
	cin >> num;
	for(e = 1;abs(n-num)>=num;count++){
		n = n / count;
		e = e + n;
	}
	cout << fixed << setprecision(6) << e;
	return 0;
}

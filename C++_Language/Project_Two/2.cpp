#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int a;
	double result;
	cin >> a;
	result = (cos(50.0 / 360 * 2 * 3.14159) + sqrt(37.5))/ (a + 1) * 1.0;
	cout << fixed << setprecision(2) << result << endl;
	return 0;
}

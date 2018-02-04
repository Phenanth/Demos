#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int total, max, min;
	double ave;
	total = a + b + c;
	ave = total / 3.0;
	max = min = a;
	(b > max)?(max = b):((c > max)?(max = c):1);
	(c > max ? max = c:1);
	(b < min)?(min = b):((c < min)?(min = c):1);
	(c < min ? min = c:1);
	cout << total << endl << ave << endl << min << endl << max << endl;
	return 0;
}
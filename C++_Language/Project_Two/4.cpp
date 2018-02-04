#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double a, b, c, delta, solution, solution1, solution2;
	cin >> a >> b >> c;
	if(a == 0 && b != 0){//一个实根
		solution = -c / b;
		cout << fixed << setprecision(2) << "x=" << solution;
	}
	else if(a == 0 && b == 0 && c == 0)//无穷解
		cout << "Infinitely solution";
	else if(a == 0 && b == 0 && c != 0)//无解
		cout << "No solution";
	else {
		delta = b * b - 4 * a * c;
		solution1 = (-b + sqrt(delta))/ (2 * a);
		solution2 = (-b - sqrt(delta))/ (2 * a);
		if(delta == 0)//两个相同
			cout << fixed << setprecision(2) << "x1=x2=" << solution1;
		if(delta < 0)//虚根
			cout << "Imaginary root";
		if(delta > 0) //不同根
			cout << fixed << setprecision(2) << "x1=" << solution1 << ";" << "x2=" << solution2;
	}
	return 0;
}

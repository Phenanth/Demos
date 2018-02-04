#include <iostream>
#include <cmath>
using namespace std;


double computeArea(int n, double side){
	if(abs(side) < 1e-6 || abs(n) < 1e-6)
		return 0;
	else {
		double area = n * side * side / (4.0 * tan(3.14159 / n));
		return area;
	}
}

int main(){
	int n;
	cin >> n;
	double side;
	cin >> side;
	cout << computeArea(n, side) << endl;
	return 0;
}

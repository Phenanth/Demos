#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int radius, area, height;
	double volume;
	const int LITER = 20000;
	const double PI = 3.14159;
	cin >> height >> radius;
	volume = PI * radius * radius * height;
	cout << ceil(LITER / volume);
	return 0;
}

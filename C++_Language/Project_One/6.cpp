#include <iostream>
using namespace std;

int main(){
	const double PI = 3.14159;
	double area, radius, volume, height;
	cin >> radius >> height;
	area = PI * radius * radius;
	volume = area * height;
	cout << volume;
	return 0;

}

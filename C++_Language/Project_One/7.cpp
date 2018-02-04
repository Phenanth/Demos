#include <iostream>
using namespace std;

double computeArea(double outside, double inside);

int main(){
	const double PI = 3.14159;
	double inside, outside, area;
	cin >> outside >> inside;
	area = computeArea(outside,inside);
	cout << area;
	return 0;
}

double computeArea(double outside, double inside){
	const double PI =3.14159;
	double area_outside, area_inside;
	area_outside = PI * outside * outside;
	area_inside = PI * inside * inside;
	return area_outside - area_inside;
}


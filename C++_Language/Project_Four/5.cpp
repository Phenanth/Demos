#include <iostream>
#include <cmath>
using namespace std;

inline bool isValid(double side1,double side2, double side3){
	if((side1 + side2 > side3)&&(side1 + side3 > side2)&&(side2 + side3 > side1))
		return true;
	else return false;
}

double computeArea(double radius=1){
	if(abs(radius)<1e-6 || radius < 0)
		return 0;
	else return 3.14159 * radius * radius;
}

double computeArea(double width, double height){
	if(abs(width)<1e-6 || abs(height)<1e-6 || width < 0 || height < 0)
		return 0;
	else return width * height;
}

double computeArea(double side1, double side2, double side3){
	if(isValid){
		double p = 1/2.0*(side1+side2+side3);
		return (sqrt(p*(p - side1)*(p - side2)*(p - side3)));
	}
	else if(isValid == 0) return 0;
}
int main(){
	double radius=0, width=0, height=0;
	double side1=0, side2=0, side3=0;
	cin >> radius >> width >> height;
	cin >> side1 >> side2 >> side3;
	cout << computeArea(radius) << endl << computeArea(width,height) << endl << computeArea(side1, side2, side3) << endl;
	cin.get();
	return 0;

}


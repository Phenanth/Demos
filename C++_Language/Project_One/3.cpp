#include <iostream>
using namespace std;

double calFahrenheit(double celsius);

int main(){
	double fahrenheit,celsius;
	cin >> celsius;
	fahrenheit = calFahrenheit(celsius);
	cout << fahrenheit;
	return 0;
}

double calFahrenheit(double celsius){
	return (9.0 / 5.0) * celsius + 32;
}

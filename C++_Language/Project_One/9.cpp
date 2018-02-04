#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calFIV(double iAmout,double monIR,int months);

int main(){
	double iAmout,yearIR;
	int years;
	const int MONTHS = 12;
	cin >> iAmout >> yearIR >> years;
	cout << fixed << setprecision(2) << calFIV(iAmout,yearIR / MONTHS,years * MONTHS);

}

double calFIV(double iAmout,double monIR,int months){
	return iAmout * pow((1 + monIR / 100),months);
}
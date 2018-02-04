#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double grade,point;
	int cla;
	do{
		cin >> grade;
	}while(grade < 0 || grade > 100);	 
	cla = grade / 10;
	point = (grade * 1.0  - 50.0) / 10;
	switch(cla){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:cout << "Failed";break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:cout << fixed << setprecision(1) << point;break;
		default:cout << "Invalid" << endl;break;
	}
	return 0;
}

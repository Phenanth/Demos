#include <iostream>
using namespace std;

int main(){
	int grade,cla;
	do{
		cin >> grade;
	}while(grade < 0 && grade > 100);
	cla = grade / 10;
	switch(cla){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:cout << "E" << endl;break;
		case 6:cout << "D" << endl;break;
		case 7:cout << "C" << endl;break;
		case 8:cout << "B" << endl;break;
		case 9:
		case 10:cout << "A" << endl;break;
		default:cout << "Invalid" << endl;
	}
	return 0;
}
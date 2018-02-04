#include <iostream>
using namespace std;

int main(){
	int money;
	int hun = 0, fi = 0, tw = 0, ten = 0, five = 0, one = 0;
	cin >> money;
	if(money != 0){
		hun = money / 100;
		if(hun != 0)
			money %= hun * 100;
		fi = money / 50;
		if(fi != 0)
			money %= fi * 50;
		tw = money / 20;
		if(tw != 0)
			money %= 20 * tw;
		ten = money / 10;
		if( ten != 0)
			money %= 10 * ten;	
		five = money / 5;
		if(five != 0)
			money %= 5 * five;
		one = money;
	}
	cout << hun << endl << fi << endl << tw << endl << ten << endl << five << endl << one;
	return 0;
}

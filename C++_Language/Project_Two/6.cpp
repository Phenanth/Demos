#include <iostream>
using namespace std;

int main(){
	double a, b, c;
	cin >> a >> b >> c;
	if(a > 0 && b > 0 && c > 0){
		double quarr = a + b + c;
		if(a + b > c && a + c > b && b + c > a)
			cout << quarr;
		else cout << "Invalid";
	}else cout << "Invalid";
	return 0;
}

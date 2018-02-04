#include <iostream>
using namespace std;

int main(){
	int num, result;
	cin >> num;
	cout << num << " divisible by 2 and 3?";
	if(num % 2 == 0 && num % 3 == 0)
		cout << "true" << endl;
	else cout << "false" << endl;
	cout << num << " divisible by 2 or 3?";
	if(num % 2 == 0 || num % 3 == 0)
		cout << "true" << endl;
	else cout << "false" << endl;
	cout << num << " divisible by 2 or 3,but not both?";
	if((num % 2 == 0)&&(num % 3 != 0) || (num % 2 != 0)&&(num % 3 == 0))
		cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}

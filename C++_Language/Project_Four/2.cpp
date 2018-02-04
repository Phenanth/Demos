#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int n){
	int temp = 0,np = n;
	if(n == 0)
		return false;
	while(n > 0){
		temp = temp * 10 + n % 10;
		n /= 10;
	}
	if(np == temp)
		return true;
	else return false;
}

int main(){
	int n;
	cin >> n;
	cout << boolalpha << isPalindrome(n) << endl;
	return 0;
}

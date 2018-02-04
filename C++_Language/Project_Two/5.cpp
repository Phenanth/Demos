#include <iostream>
using namespace std;

int main(){
	int x;
	cin >> x;
	if(x < 0){
		int result = x + 1;
		cout << result << endl;
	}else if(x >= 0 && x < 100){
		int result = x * x * x;
		cout << result << endl;
	}else{
		int result = x * x + 5;
		cout << result << endl;
	} 
	return 0;
}
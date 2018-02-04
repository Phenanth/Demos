#include <iostream>
using namespace std;

int main(){
	int money, ticks[5] = {100, 50, 20, 10, 5}, i, counter[5] = {0};
	cin >> money;
	if(money != 0)
		for(i = 0; i < 5; i++){
			counter[i] = money / ticks[i];
			if(counter[i] != 0)
				money %= counter[i] * ticks[i];
		}
	for(i = 0; i < 5; i++)
		cout << counter[i] << endl;
	cout << money;
	return 0;

}

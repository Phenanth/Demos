#include <iostream>
using namespace std;

int main(){
	int num, posi1, posi2, posi3, posi4;
	cin >> num;
	posi1 = num / 1000, posi2 = num / 100, posi3 = num / 10, posi4 = num % 10;
	posi1 += 9, posi2 += 9, posi3 += 9, posi4 += 9;
	posi1 %= 10, posi2 %= 10, posi3 %= 10, posi4 %= 10;
	int result,temp;
	temp = posi1, posi1 = posi3, posi3 = temp;
	temp = posi2, posi2 = posi4, posi4 = temp;
	result = posi1 * 1000 + posi2 * 100 + posi3 * 10 + posi4;
	cout << result << endl;
	return 0;
}
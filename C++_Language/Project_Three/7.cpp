#include <iostream>
using namespace std;

int main(){
	int group;
	cin >> group;
	while(group--){
		int max, temp, couter = 0;
		cin >> temp;
		for(max = 1;max*2 < temp;max *= 2);
		while(max > 0){
			if(temp / max != 0){
				couter++;
				temp -= max;
			}
			max /= 2;
		}
		cout << couter << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;


int main(){
	int i, array[10], max, min;
	for(i = 0; i < 10; i++)
		cin >> array[i];
	max = min = array[0];
	int max_index = 0, min_index = 0;
	for(i = 1; i < 10; i++){
		if(array[i] > max){
			max = array[i];
			max_index = i;
		}
		if(array[i] < min){
			min = array[i];
			min_index = i;
		}
	}
	cout << max << ' ' << max_index << endl;
	cout << min << ' ' << min_index;
	return 0;
}

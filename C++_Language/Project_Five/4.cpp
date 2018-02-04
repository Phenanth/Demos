#include <iostream>
#include <stdlib.h>
using namespace std;

int cpm(const void *p, const void *q){
	return (*(int *)p - *(int *)q);
}

int main(){

//use while to repeat	
	while(1){

	//define
		int array[10001] = {0};
		int times, i;
		
	//input
		cin >> times;
	// input judge
		if(times == 0)
			break;
		for(i = 0 ; i < times; i++)
			cin >> array[i];
	
	//sort the inputed ones
		qsort(array, times, sizeof(int), cpm);

	//calculate result & output
		if(times % 2 == 1)
			cout << array[times / 2] << endl;
		else cout << (array[times / 2 - 1] + array[times / 2]) / 2 << endl;

	}

	return 0;

}


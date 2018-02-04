#include <iostream>
using namespace std;


int main(){

//define
//	int array[2] = {1,2};
	int array[100] = {0};
	int group = 0, shift = 0, i;

//input
	
	cin >> group >> shift;
	for(i = 0; i < group; i++)
		cin >> array[i];
	

//judge & shift
	if(shift != 0){
		int temp = array[0], counter = 0, index = 0;
		while(counter < group){
			if(index + shift >= group)
				index = index - group;
			int tempin = array[index + shift];
			array[index + shift] = temp;
			temp = tempin;
			index += shift;
			counter++;
		}
	}

//output
	for(i = 0; i < group; i++)
		cout << array[i] << ' ';

	return 0;
}

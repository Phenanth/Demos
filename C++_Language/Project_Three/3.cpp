#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int counter = 0,integer_count = 0, min_count = 0, sum = 0, temp;
	double average;
	cin >> temp;
	while(temp != 0){
		counter++;
		sum += temp;
		if(temp > 0)
			integer_count++;
		else min_count++;
		average = (double)sum / counter;
		cin >> temp;
	}
	if(counter == 0)
		cout << "No input" << endl;
	else{
		cout << integer_count << endl << min_count << endl << sum << endl;
		cout << fixed << setprecision(2) << average;
	}
	return 0;
}

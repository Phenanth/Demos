#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int group;
	cin >> group;
	while(group--){
		const double WALK = 1.2, BIKE = 3.0, CONSUME  = 50;
		double meter, result;
		cin >>	meter;
		result = ( CONSUME + meter / BIKE ) - ( meter / WALK);
		if(abs(result) <= 1e-6)
			cout << "All" << endl;
		else if(result < 0)
			cout << "Bike" << endl;
		else if(result > 0)
			cout << "Walk" << endl; 
	}
	return 0;
}

#include <iostream>
using namespace std;

int main(){ 
	for(int men = 0; men <= 15; ++men)
		for(int women = 0; women <= 23; ++women)
			for(int child = 0; child <= 45; child+=2)
				if((men + women + child ) == 45){
					if((men * 6 + women * 4 + child * 1 ) == 90)
						cout << men << ',' << women << ',' << child << endl;
					}
	return 0;
}

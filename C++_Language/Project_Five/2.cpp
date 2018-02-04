#include <iostream>
using namespace std;

int main(){
	int array[10][10] = {0};
	int i, j, side;
	cin >> side;
	for(i = 0; i < side; i++){
		for(j = 0; j < side; j++)
			cin >> array[i][j];
	}
	int whether = 1;
	for(i = 1; i < side; i++)
		for(j = 0; j + i <= side; j++){
			if(array[i][j] != 0)
				whether--;
				break;
		}
	if(whether != 1)
		cout << "No";
	else cout << "Yes";
	return 0;
}

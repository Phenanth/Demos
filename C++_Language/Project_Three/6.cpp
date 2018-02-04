#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int side, i;
	int line;
	char ch;
	cin.get(ch);
	cin >> side;
	for(line = 1; line <= side - 1;line++){
		for(int i = side - line ; i >= 2 ; i--)
			cout << ' ';
		if(line == 1)
			cout << ' ' << ch ;
		else cout << left << setw(2 * line) << setfill(ch)  << ' ' ;
		cout << endl;
	}
	cout << setw(2 * line - 1) << setfill(ch) << ch << endl;
	for(line = side - 1; line >= 1 ; line--){
		for(int i = 2; i <= side - line; i++)
			cout << ' ';
		if(line == 1)
			cout << ' ' << ch;
		else cout << left << setw(2 * line) << setfill(ch) << ' ';
		cout << endl;
	}
	return 0;
}

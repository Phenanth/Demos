#include <iostream>
using namespace std;

int main(){
//define
	int array[10][10] = {0}, max_row[10] = {0}, min_col[10] = {0};
	int m, n, i, j;

//input
	do{
		cin >> m >> n;
	}while(m < 2 || m > 10 || n < 2 || n >> 10);	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			cin >> array[i][j];

//select maximum per row
	for(i = 0; i < m; i++){
		max_row[i] = array[i][0];
		for(j = 1; j < n; j++){
			if(array[i][j] > max_row[i])
				max_row[i] = array[i][j];
		}
	}

//select minimum per column
	for(j = 0; j < n ; j++){
		min_col[j] = array[0][j];
		for(i = 1; i < m; i++)
			if(array[i][j] < min_col[j])
				min_col[j] = array[i][j];
	}

	for(i = 0; i < m; i++)
		if(max_row[i] != 0)
			cout << max_row[i] << ' ';
	cout << endl;

	for(i = 0; i < n; i++)
		if(min_col[i] != 0)
			cout << min_col[i] << ' ';
	cout << endl;

//judge if maximum per row equals minimum per column
	int we = 0; 
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			if(max_row[i] == min_col[j]){
				we++;
				break;
			}else continue;
		if(max_row[i] == min_col[j])
			break;
	}

//output
	if(we == 0)
		cout << "No saddle point";
	else cout << i << ' ' << j << ' ' << array[i][j];


	return 0;
}

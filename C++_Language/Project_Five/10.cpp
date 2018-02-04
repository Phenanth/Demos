#include <iostream>
#include <iomanip>
using namespace std;

void mulMatrix(int **a, int **b, int **c, int cRow,int cCol, int aCol){
	for (int i = 0; i < cRow; i++){  
		for (int j = 0; j < cCol; j++){  
			c[i][j] = 0;
			for (int k = 0; k < aCol; k++)  
				c[i][j] += a[i][k] * b[k][j];
		}
	}  
}

void printMatrix(int **array, int arrayRow, int arrayCol){
	for(int i = 0; i < arrayRow; i++){
		for(int j = 0; j < arrayCol; j++){
			cout << array[i][j];
			if(j != arrayCol - 1)
				cout << ' ';
		}
		if(i != arrayRow - 1)
			cout << endl;
	}
}

int main(){
	int aRow, aCol, bRow, bCol, cRow, cCol;
	cin >> aRow >> aCol >> bCol;
	bRow = aCol, cRow = aRow, cCol = bCol;
	int **a = new(nothrow) int *[aRow];
	int **b = new(nothrow) int *[bRow];
	int **c = new(nothrow) int *[cRow];
	int i;
	for(i = 0; i < aRow ; i++)
		a[i] = new(nothrow) int[aCol];
	for(i = 0; i < bRow; i++)
		b[i] = new(nothrow) int[bCol];
	for(i = 0; i < cRow; i++)
		c[i] = new(nothrow) int[cCol];
	for(i = 0; i < aRow; i++)
		for(int j = 0; j < aCol; j++)
			cin >> a[i][j];
	for(i = 0; i < bRow; i++)
		for(int j = 0; j < bCol; j++)
			cin >> b[i][j];	
	mulMatrix(a, b, c, cRow, cCol, aCol);
	printMatrix(c, cRow, cCol);

	return 0;
}

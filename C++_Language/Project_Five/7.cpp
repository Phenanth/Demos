#include <iostream>
#include <cmath>
using namespace std;
double mean(const double x[], int arraySize){
	double sum = 0;
	for(int i = 0; i < arraySize; ++i)
		sum +=	x[i];
	return sum / arraySize;
}
double deviation(const double x[], int arraySize){
	double mean, sum = 0,  temp = 0;
	for(int i = 0; i < arraySize; ++i)
		sum +=	x[i];
	mean = sum / arraySize;
	for(int i = 0; i < arraySize; i++)
		temp += pow(x[i] - mean, 2);
	return sqrt(temp / (arraySize - 1));
}

int main(){
	double x[10] = {583, 566, 58, 632, 244, 485, 600, 432, 88, 562};
	const int arraySize = 10;
	cout << mean(x, arraySize) << endl;
	cout << deviation(x, arraySize) << endl;
	return 0;

}

#include <iostream>
#include <stdlib.h>
using namespace std;

int comp(const void *p, const void*q){
	return *((int *)q) - *((int *)p);
}

int main(){
	int group, i, array[101], k;
	cin >> group >> k;
	for(i = 0; i < group; i++)
		cin >> array[i];
	qsort(array, group, sizeof(int), comp);
	cout << array[k-1] << endl;
	return 0;
}

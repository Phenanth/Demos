#include <iostream>
using namespace std;

int isPrime(int x){
	int i;
	for(i=2;i<=x;i++){
		if(x%i==0)
			break;
	}
	if(x==i)
		return 1;
	else return 0;
}

int main(){
	int num;
	cin >> num;
	for(int i = 0; i <= num; i++){
		if(isPrime(i) && num % i == 0){
			cout << i << endl;
			num /= i;
			i = 0;
		}
	}
	return 0;
}

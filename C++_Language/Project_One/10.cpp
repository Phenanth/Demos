#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void timeTake(int times,int timed,int* hourtake, int* mintake);
int isIllegal(int times, int timed);
inline int minutes(int time) {
	return time / 100 * 60 + time % 100;
}

int main(){
	int hourtake, mintake, times, timed;
	do{
		cin >> times >> timed;
	}while(isIllegal(times,timed));
	timeTake(times,timed,&hourtake,&mintake);
	cout << setw(2) << setfill('0') << hourtake << ':';
	cout << setw(2) << setfill('0') << mintake;
	return 0;
}

void timeTake(int times,int timed,int* hourtake, int* mintake){
	int minute;
	minute = minutes(timed) - minutes(times);
	*hourtake = minute / 60;
	*mintake = minute % 60;
}

int isIllegal(int times, int timed){
	if(timed < times)
		return 1;
	else if(times < 0 || times > 2399 || times % 100 > 59)
		return 1;
	else if(timed < 0 || timed > 2399 || timed % 100 > 59)
		return 1;
	else return 0;
}

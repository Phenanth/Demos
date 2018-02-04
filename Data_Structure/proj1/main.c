#include <stdio.h>
#include <time.h>
#include "functions.h"


int main() {
	clock_t start, stop;
	double duration;
	int arr[6000] = { 0 };
	start = clock();
	// function();
	int K = 100000;
	while(K--){
		//iterativeSequentialSearch(arr, 10000);
		//recursiveSequentialSearch(arr, 10000, 10000);// 6000时K=100000则程序停止工作
		iterativeBinarySearch(arr, 6000, 6000);
	}
	stop = clock();
	duration = ((double)(stop - start)) / 1000;
	double dur = duration / 100000;
	printf("Ticks: %lu, K: %d, Total time: %lf, Duration: %lf.\n", (stop - start), 100000, (duration), (dur) );
	return 1;

}




/*
Ticks: 61, K: 100000, Total time: 0.061000, Duration: 0.000001
Ticks: 158, K: 100000, Total time: 0.158000, Duration: 0.000002.
Ticks: 392, K: 100000, Total time: 0.392000, Duration: 0.000004.
Ticks: 657, K: 100000, Total time: 0.657000, Duration: 0.000007.
Ticks: 1464, K: 100000, Total time: 1.464000, Duration: 0.000015.
Ticks: 2344, K: 100000, Total time: 2.344000, Duration: 0.000023.
Ticks: 3019, K: 100000, Total time: 3.019000, Duration: 0.000030.
Ticks: 3616, K: 100000, Total time: 3.616000, Duration: 0.000036.



Ticks: 244, K: 100000, Total time: 0.244000, Duration: 0.000002.
Ticks: 1205, K: 100000, Total time: 1.205000, Duration: 0.000012.
Ticks: 2523, K: 100000, Total time: 2.523000, Duration: 0.000025.
Ticks: 5497, K: 100000, Total time: 5.497000, Duration: 0.000055.
Ticks: 11323, K: 100000, Total time: 11.323000, Duration: 0.000113.
//from 4000
Ticks: 1793141, K: 100000, Total time: 1793141.000000, Duration: 17.931410.
Ticks: 2680147, K: 100000, Total time: 2680147.000000, Duration: 26.801470.
Ticks: 3695568, K: 100000, Total time: 3695568.000000, Duration: 36.955680.
Ticks: 4745787, K: 100000, Total time: 4745787.000000, Duration: 47.457870.



Ticks: 6, K: 100000, Total time: 0.006000, Duration: 0.000000.
Ticks: 7, K: 100000, Total time: 0.007000, Duration: 0.000000.
Ticks: 18, K: 100000, Total time: 0.018000, Duration: 0.000000.
Ticks: 19, K: 100000, Total time: 0.019000, Duration: 0.000000.
Ticks: 11, K: 100000, Total time: 0.011000, Duration: 0.000000.
Ticks: 17, K: 100000, Total time: 0.017000, Duration: 0.000000.
Ticks: 22, K: 100000, Total time: 0.022000, Duration: 0.000000.
Ticks: 25, K: 100000, Total time: 0.025000, Duration: 0.000000.



it_sequential

Ticks: 29098, K: 100000, Total time: 29.098000, Duration: 0.000291.//100
Ticks: 148721, K: 100000, Total time: 148.721000, Duration: 0.001487.
Ticks: 302167, K: 100000, Total time: 302.167000, Duration: 0.003022.
Ticks: 613438, K: 100000, Total time: 613.438000, Duration: 0.006134.
Ticks: 1322733, K: 100000, Total time: 1322.733000, Duration: 0.013227.
Ticks: 1847702, K: 100000, Total time: 1847.702000, Duration: 0.018477.
Ticks: 2484201, K: 100000, Total time: 2484.201000, Duration: 0.024842.
Ticks: 2994143, K: 100000, Total time: 2994.143000, Duration: 0.029941.

re_sequential

Ticks: 48175, K: 100000, Total time: 48.175000, Duration: 0.000482.//100
Ticks: 223438, K: 100000, Total time: 223.438000, Duration: 0.002234.
Ticks: 448435, K: 100000, Total time: 448.435000, Duration: 0.004484.
Ticks: 904279, K: 100000, Total time: 904.279000, Duration: 0.009043.
Ticks: 1948379, K: 100000, Total time: 1948.379000, Duration: 0.019484.
Ticks: 3006860, K: 100000, Total time: 3006.860000, Duration: 0.030069.
Ticks: 3946706, K: 100000, Total time: 3946.706000, Duration: 0.039467.
Ticks: 4986649, K: 100000, Total time: 4986.649000, Duration: 0.049866.


bi
Ticks: 8235, K: 100000, Total time: 8.235000000, Duration: 0.000082350.
Ticks: 11708, K: 100000, Total time: 11.708000000, Duration: 0.000117080. //500
Ticks: 14615, K: 100000, Total time: 14.615000000, Duration: 0.000146150.
Ticks: 15186, K: 100000, Total time: 15.186000000, Duration: 0.000151860.
Ticks: 16749, K: 100000, Total time: 16.749000000, Duration: 0.000167490.
Ticks: 18098, K: 100000, Total time: 18.098000000, Duration: 0.000180980.
Ticks: 18145, K: 100000, Total time: 18.145000000, Duration: 0.000181450.
Ticks: 19722, K: 100000, Total time: 19.722000000, Duration: 0.000197220.

*/
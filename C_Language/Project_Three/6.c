#include <stdio.h>
//using multiplicating 2 to avoid the decimals.


int main(){
	int men, women, child;
	printf("how can you make 45 people who is consisted of man or women or child to deliver 45 bricks?\n");
	for(men = 0; men <= 15; ++men)
		for(women = 0; women <= 23; ++women)
			for(child = 0; child <= 45; child+=2)
				if((men + women + child ) == 45){
					if((men * 6 + women * 4 + child * 1 ) == 90)
					printf("the menber is like : %dmen, %dwomen, %dchilds\n",men,women,child);
				}
	return 0;
}

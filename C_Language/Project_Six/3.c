#include <stdio.h>
#define ROW 10
#define COLUMN 10

int isUeArray(int line[][COLUMN],int n);

int main(){
	int i,j,n;
	int	line[ROW][COLUMN]= {{1,2,3,4,5,6,7,8,9,0},
							{0,3,4,5,6,7,2,3,5,2},
							{0,0,5,3,6,2,1,6,7,4},
							{2,3,6,4,3,8,3,6,2,5},
							{2,3,5,3,6,1,4,3,6,7},
							{2,3,5,2,6,3,6,3,4,6},
							{6,2,2,3,5,2,3,3,5,3},
							{4,2,3,5,1,2,4,1,3,5},
							{3,2,3,2,2,3,5,2,3,3},
							{2,4,2,3,5,6,7,4,5,3}};
	do{
		printf("Input a n:");
		scanf("%d",&n);
	}while(n<2||n>10);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++)
			printf("%2d",line[i][j]);
		printf("\n");
	}
	if(isUeArray(line,n)==1)
		printf("Yes\n");
	else printf("No\n");

	return 0;
}

int isUeArray(int line[][COLUMN],int n){
	int i,j,whether=1;
	if(n>=2&&n<=10){
		for(i = 1;i < n;i++){
			if(whether==0){
				i--;
				break;
			}
			for(j = 0;j < i;j++){
				if(line[i][j]!=0){
					whether--;
					break;
				}
			}
		}
	}
	return whether;
}

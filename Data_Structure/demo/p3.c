// Write a function, peval(), that evaluates a polynomial at some value, x0.
// Try to minimize the number of operations and give out the time complexity.
#include <stdio.h>
#include <math.h>
#define MAX_TERMS 100
typedef struct {
	float coef; // 系数
	int expon; // 指数
} polynomial;

void readPoly(polynomial terms[], int* avail);
double peval(polynomial terms[], int avail, double x0);
void printPoly(polynomial terms[], int avail);


int main(){
	polynomial terms[MAX_TERMS];
	int avail = 0;
	double x0, result;
	readPoly(terms, &avail);
	printf("%s\n", "Input the value of x0:");
	scanf("%lf", &x0);
	result = peval(terms, avail, x0);
	printf("%s%.3lf\n", "The result of the evaluation is: ", result);
	printPoly(terms, avail);
	return 0;
}

void readPoly(polynomial terms[], int* avail){
	int i;
	printf("%s\n", "Input the number of how many polynomials you want to input? (Input a number which is no bigger than 100.)");
	scanf("%d", avail);
	printf("%s\n", "Input the coefficient and the exponent of the polynomial:");
	for (i = 0; i < *avail; i++){
		scanf("%f %d", &terms[i].coef, &terms[i].expon);
		if (i == (*avail)-1)
			break;
	}
	printf("%s\n", "Polynomial successfully inputed.");
}

double peval(polynomial terms[], int avail, double x0){
	int i;
	double result = 0;
	for (i = 0; i < avail; i++){
		result += terms[i].coef * pow(x0, terms[i].expon);
	}
	return result;
}

void printPoly(polynomial terms[], int avail){
	int i;
	printf("%s\n", "The polynomial is:");
	for (i = 0; i < avail; i++){
		printf("%.2f*x^%d ", terms[i].coef, terms[i].expon);
		if (i != avail-1)
			printf("%s", "+ ");
	}
	printf("\nPolyminal successfully printed\n");
}

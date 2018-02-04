#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

typedef double Coefficient;
typedef unsigned int Exponent;
typedef struct {
	Coefficient coef[MAX];
	Exponent expon[MAX];
} Polynomial;

Polynomial Zero();
int isZero(Polynomial poly);
Coefficient Coef(Polynomial poly, Exponent expon);
Exponent Lead_Exp(Polynomial poly);
Polynomial Attach(Polynomial poly, Coefficient coef, Exponent expon);
Polynomial Remove(Polynomial poly, Exponent expon);
Polynomial SingleMult(Polynomial poly, Coefficient coef, Exponent expon);
Polynomial Add(Polynomial poly1, Polynomial poly2);
Polynomial Mult(Polynomial poly1, Polynomial poly2);
void calculator(Polynomial poly1, Polynomial poly2, double x0, double* y1, double* y2);

Polynomial readPoly();
void printPoly(Polynomial poly);
double evaluate(Polynomial poly, double x0);
void testing(Polynomial poly1, Polynomial poly2);


int main(){
	Polynomial poly1 = readPoly(), poly2 = readPoly();
	double x0, y1, y2;
	printf("%s\n", "Input the x0 you want to evaluate:");
	scanf("%lf", &x0);

	calculator(poly1, poly2, x0, &y1, &y2);
	printf("%s%.3lf\n%s%.3lf\n", "Resulting number of the C(x) is: ", y1, "Resulting number of the D(x) is: ", y2);

	return 0;
}


//`````````````````````````````````````````


Polynomial Zero(){
	Polynomial temp;
	int i;
	for (i = 0; i < MAX; i++)
		temp.coef[i] = 0, temp.expon[i] = 0;
	return temp;
}

int isZero(Polynomial poly){
	int i;
	Polynomial temp = Zero();
	for (i = 0; i < MAX; i++)
		if(poly.coef[i] != temp.coef[i] || poly.expon[i] != temp.coef[i])
			break;
	if (i != MAX)
		return 0;
	else return 1;
}

Coefficient Coef(Polynomial poly, Exponent expon){
	int i;
	for (i = 0; i < MAX; i++){
		if(expon == poly.expon[i]){
			return poly.coef[i];
		} else continue;
	}
	return 0;
}

Exponent Lead_Exp(Polynomial poly){
	if (isZero(poly))
		return 0;
	else return poly.expon[0];
}

Polynomial Attach(Polynomial poly, Coefficient coef, Exponent expon) {
	int startt = 0, starto = 0, opt=0;
	Polynomial temp = Zero();
	while (!(poly.expon[starto] == 0 && poly.coef[starto] == 0)) {
		if (expon == poly.expon[starto]) {
			printf("%s\n", "Exponent Exsited.");
			exit(EXIT_FAILURE);
		}
		if ((poly.expon[starto-1] > expon && poly.expon[starto] < expon) || expon > Lead_Exp(poly)) {
			temp.expon[startt] = expon, temp.coef[startt] = coef;
			startt++, opt++;		
			break;
		}
		else {
			temp.expon[startt] = poly.expon[starto], temp.coef[startt] = poly.coef[starto];
			starto++, startt++;
		}
	}
	while (!(poly.expon[starto] == 0 && poly.coef[starto] == 0)) {
		temp.expon[startt] = poly.expon[starto], temp.coef[startt] = poly.coef[starto];
		starto++, startt++;
	}
	if (opt == 0) {
		temp.expon[startt] = expon, temp.coef[startt] = coef;
	}
	return temp;
}

Polynomial Remove(Polynomial poly, Exponent expon){
	int startt = 0, starto = 0, exist = 0;
	Polynomial temp = Zero();
	while (!(poly.expon[starto] == 0 && poly.coef[starto] == 0)) {
		if(expon == poly.expon[starto]){
			exist++, starto++;
			continue;
		} else {
			temp.expon[startt] = poly.expon[starto], temp.coef[startt] = poly.coef[starto];
			startt++, starto++;
		}
	}
	if (exist == 0) {
		printf("%s\n", "Exponent Dosen't Exsit");
		exit(EXIT_FAILURE);
	} else return temp;
}

Polynomial SingleMult(Polynomial poly, Coefficient coef, Exponent expon){
	int i;
	Polynomial temp = Zero();
	for (i = 0; i < MAX; i++){
		if (poly.coef[i] != 0) {
			temp.coef[i] = poly.coef[i] * coef;
			temp.expon[i] = poly.expon[i] + expon;
		}
	}
	return temp;
}

Polynomial Add(Polynomial poly1, Polynomial poly2){
	int i, p1, p2;
	Polynomial temp = Zero();
	for (i = 0, p1 = 0, p2 = 0; i < MAX ; i++){
		if(poly1.coef[p1] == 0 || poly2.coef[p2] == 0){
			break;
		}
		if (poly1.expon[p1] == poly2.expon[p2]) {
			temp = Attach(temp, poly1.coef[p1]+poly2.coef[p2], poly1.expon[p1]);
			p1++, p2++;
		} else if(poly1.expon[p1] > poly2.expon[p2]) {
			temp = Attach(temp, poly1.coef[p1], poly1.expon[p1]);
			p1++;
		} else {
			temp = Attach(temp, poly2.coef[p2], poly2.expon[p2]);
			p2++;
		}
	}
	if(poly1.coef[p1] == 0 && poly2.coef[p2] != 0){
		while(poly2.coef[p2] != 0){
			temp = Attach(temp, poly2.coef[p2], poly2.expon[p2]);
			p2++;
		}
	}
	if(poly1.coef[p1] != 0 && poly2.coef[p2] == 0){
		while(poly1.coef[p1] != 0){
			temp = Attach(temp, poly1.coef[p1], poly1.expon[p1]);
			p1++;
		}
	}
	return temp;
}

Polynomial Mult(Polynomial poly1, Polynomial poly2){
	Polynomial temp = Zero();
	while(!isZero(poly2)){
		temp = Add(temp, SingleMult(poly1, poly2.coef[0], poly2.expon[0]));
		poly2 = Remove(poly2, poly2.expon[0]);
	}
	return temp;
}

void calculator(Polynomial poly1, Polynomial poly2, double x0, double* y1, double* y2){
	Polynomial result1 = Zero(), result2 = Zero();
	result1 = Add(poly1, poly2);
	result2 = Mult(poly1, poly2);
	printf("%s\n", "Resulting polynomial of the C(x) is:");
	printPoly(result1);
	printf("%s\n", "Resulting polynomial of the D(x) is:");
	printPoly(result2);
	*y1 = evaluate(result1, x0);
	*y2 = evaluate(result2, x0);
}


// `````````````````````````````````````````


Polynomial readPoly(){
	int i, coef, expon, avail;
	Polynomial poly = Zero();
	printf("%s\n", "Input the temrs of the polynomial. \n (Input a number which is no bigger than 50.)");
	scanf("%d", &avail);
	printf("%s\n", "Input the coefficient and the exponent of the polynomial by the exponent descending order:");
	for (i = 0; i < avail; i++){
		scanf("%lf %d", &poly.coef[i], &poly.expon[i]);
	}
	return poly;
}

void printPoly(Polynomial poly){
	int i=0;
	while ( !(poly.expon[i]==0 && poly.coef[i]==0) ) {
		printf("%.2f*x^%d ", poly.coef[i], poly.expon[i]);
		if ( !(poly.expon[i+1]==0 && poly.coef[i+1]==0) )
			printf("%s", "+ ");
		i++;
	}
	printf("\n");
}

double evaluate(Polynomial poly, double x0){
	int i = 0;
	double result = 0;
	while (poly.coef[i] != 0) {
		result += poly.coef[i] * pow(x0, poly.expon[i]);
		i++;
	}
	return result;
}

void testing(Polynomial poly1, Polynomial poly2){

	int coef, expon;
	Polynomial temp = Zero();

	// Attach testing.
	//scanf("%d %d", &coef, &expon);
	//temp = Attach(poly1, coef, expon);
	//printPoly(temp);
	//rintf("%d\n",  Lead_Exp(temp));

	// Remove testing.
	//temp = Remove(poly1, expon);
	//printPoly(temp);

	// SingleMult testing.
	//temp = SingleMult(poly1, coef, expon);
	//printPoly(temp);

	// Add testing. 
	//temp = Add(poly1, poly2);
	//printPoly(temp);

	// Mult testing.
	//temp = Mult(poly1, poly2);
	//printPoly(temp);
}
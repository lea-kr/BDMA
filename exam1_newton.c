#include <stdio.h>
#include <math.h>

double function(double x);
double function(double x){
	return sqrt(64 / (x * x) - 1) - tan(x);
}

double dfunction(double x);
double dfunction(double x){
	return -64 / (sqrt(64 / (x * x) - 1) * x * x * x) - 1 / (cos(x) * cos(x));
}

int main(){
	double x_new, x_old, seed;
	double epsilon = 1e-8;
	int count = 0;
	
	scanf("%le", &seed);
	
	x_new = seed;
	
	do{
		x_old = x_new;
		x_new = x_old - function(x_old) / dfunction(x_old);
		count++;
	}while(fabs(x_new - x_old) > epsilon && count < 10000);
	
	printf("Solution = %f\n", x_new);

	return 0;
}
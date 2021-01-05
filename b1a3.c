#include <stdio.h>
#include <math.h>

double function(double x);
double function(double x){
	return tanh(x);
}

double dfunction(double x);
double dfunction(double x){
	return 1 / (cosh(x) * cosh(x));
}

int main(){
	double x_new, x_old, seed;
	double epsilon = 1e-8;
	int count = 0;
	
	seed = 0.5;
	x_new = seed;
	
	do{
		x_old = x_new;
		x_new = x_old - function(x_old) / dfunction(x_old);
		count++;
	} while (fabs(x_new - x_old) > epsilon && count < 100000);
	
	printf("%f\n bla", x_new);
	
	return 0;
}
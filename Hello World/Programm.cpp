#include <stdio.h>
#include <locale.h>
#include <math.h> 

const double g = 9.81;
double height (double t);


int main()
{
	setlocale(LC_ALL, "Russian");
	double t = 0.05;
	double dt = 0.05;
	while (t <= 1.0001)
	{
		double h = height(t);
		printf(
			"t=%.2lf sec\th=%.1lf cm\n", t, h * 100.
		);
		t += dt;

	}
	
	return 0;
}
double height(double t)
{
	return (g * t * t / 8.);
}
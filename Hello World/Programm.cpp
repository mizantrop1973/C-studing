#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//Ïðèáëèæåííûå ðàñ÷åò ëîãàðèôìà ñ çàäàííîé òî÷íîñòüþ ÈÍÂÀÐÈÀÍÒ

double log(double a, double y, double eps);

int main()

{
	double a, y, eps;
	setlocale(LC_ALL, "Russian");
	printf(" ÏÐÈÁËÈÆÅÍÍÛÉ ÐÀÑ×ÅÒ ËÎÃÀÐÈÔÌÀ (ÈÍÂÀÐÈÀÍÒ)\n\n");
	
	while (true)
	{
		
		printf("\n Ââåäèòå  îñíîâàíèå ëîãîðèôìà à > 1  : ");
		scanf_s("%lf", &a);
		printf("\n Ââåäèòå ÷èñëî ëîãàðèôìà y > 0  :  ");
		scanf_s("%lf", &y);
		printf("\n Çàäàéòå òî÷íîñòü eps  :  ");
		scanf_s("%lf", &eps);

		double x = log(a, y, eps);
		printf("\n ÎÒÂÅÒ :  Ëîãàðèôì ÷èñëà %lf ïî îñíîâàíèþ %lf = %lf  \n", y, a, x);

		printf("\n ÏÐÎÂÅÐÊÀ : a ^ x =  %lf\n\n\n", pow(a, x));
				
		printf("\n ÍÎÂÛÉ ÐÀÑ×ÅÒ\n");
	}

	return 0;

}

double log(double a, double y, double eps)
{
	assert(a > 0. && a !=  1.);
	bool inverse = false;
	if (a < 1.)
	{
		inverse = true;
		a = 1. / a;
	}
	double x = 0;
	double z = y;
	double t = 1;
	assert(pow(a, x) * pow(z, t) == y);


	while (z < 1. / a || z > a || fabs(t) > eps)
	{
		if (z > a)
		{
			z = z / a;
			x = x + t;
		}
		else if (z < 1 / a)
		{
			z = z * a;
			x = x - t;
		}
		else
		{
			t = t / 2;
			z = z*z;
		}
	}
	if (inverse)
		x = (-x);

	return x;

}

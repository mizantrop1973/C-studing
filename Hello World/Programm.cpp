#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

double squareRoot(double a, double eps);

int main()

{
	setlocale(LC_ALL, "Russian");
	printf(" ����������� ���������� ����� ����� � �������� ���������");
	double a, r, eps;
	while (true)
	{
		printf("\n ������� a:  ");
		scanf("%lf", &a);
			if(a<0)
			break;

		printf(" ������� eps:  ");
		scanf("%lf", &eps);
				
		r = squareRoot(a, eps);
		printf("\n r = %lf\n", r);
		printf("\n �������� 1: sqrt(a) = %lf\n", sqrt(a));
		printf(" �������� 2: r * r = %lf\n", r * r);
		printf("\n ����� ������\n");
	}

	return 0;

}
double squareRoot(double a, double eps)
{
	assert (a >= 0.); // �������� ������ ������� #include <cassert>
	double x = a;
	while (fabs(x * x - a) > eps)
	{
		x = (x + a / x) / 2.;
	}
	fflush(stdin);
	return x;

}

		

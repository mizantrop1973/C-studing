#include <stdio.h>
#include <locale.h>
#include <math.h> 

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	//a*x*x + b*x + c*x = 0
	//a = 1.; b = -3.; c = 2.;

	printf ("������� ������������ ��������:\n");
	printf("K���������� a = ");
	scanf_s("%lf", &a);
	printf("K���������� b = ");
	scanf_s("%lf", &b);
	printf("K���������� c = ");
	scanf_s("%lf", &c);

	double d = b * b - 4. * a * c;

	if (d < 0.)
	{
		
		printf("��� �������\n");
	}
	else
	{
		d = sqrt(d);
		double x1 = (-b + d) / (2. * a);
		double x2 = (-b - d) / (2. * a);
		printf("x1 = %lf x2 = %lf\n", x1, x2);
	}
	return 0;
}
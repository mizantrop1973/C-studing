#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

double  degree(double a, int n);

int main()

{
	setlocale(LC_ALL, "Russian");
	printf(" �������� �������� ���������� � ������� (���������)");
	double  a;
	int n;
	while (true)
	{
		printf("\n ������� ���������� � ������� ����� a:  ");
		scanf("%lf", &a);

		printf(" ������� ������� n:  ");
		scanf("%d", &n);
		if (n < 0)
			break;
		double x = degree(a, n);
		printf("\n x = %lf\n", x);
		
		printf("\n ����� ������\n");
	}

	return 0;

}
double degree(double a, int n)
{
	assert(n >= 0.); // �������� ������ ������� #include <cassert>
	double p = 1;
	double b = a;
	int k = n;
	// ����������� b ^ k  * p = a;

	while (k > 0)
	{
		if (k % 2 == 0)
		{
			k = k / 2;
			b = b * b;
		}
		else
		{
			k = k - 1;
			p = p * b;
		}
	}
	
	//fflush(stdin);
	return p;

}

		

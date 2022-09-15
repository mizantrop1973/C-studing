#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//����������� ������������������ ������ � ������� ���������

bool secSearch(double *a, int n, double x, int* idx);
const int N = 100;
int n; 
int* idx;
double x;
double a[N];
const double EPS = 0.0000001;

int main()

{
	
	setlocale(LC_ALL, "Russian");
	printf(" ����������� ������������������ ������ � �������\n\n");
	
	while (true)
	{
		printf("\n �������  ����� ������� n < N = %d :  ", N);
		scanf_s("%d", &n);
		
		while (n > N || n <= 0)
		{
			printf("\n ����� ������� ����� 1(�������) ��� ���� ����������� (%d). ���������� ��� ���\n", N);
			scanf_s("%d", &n);
		}
		printf("\n ������� ���c�� a ������ %d ������������ ����� (����� ������� �������� ENTER)  :\n", n);
		int i = 0;
				for (int i=0; i <= n - 1; i++)
		{
			printf(" a[%d] = ", i);

			scanf_s("%lf", &a[i]);
		}

		printf("\n ������ ������  :\n");
		for (i = 0; i <= n - 1; ++i)
		{
			printf(" %lf  ", a[i]); // ������ � ������� ������ ����������
			//getchar(); getchar();
		}
		printf("\n ������� ������� ������ x = ");
		scanf_s("%lf", &x);

		//bool found = secSearch(a,  n,  x, idx);
		bool found = false;

		for (int i = 0; !found && i <= (n - 1); ++i)
		{
			if (fabs(a[i] - x) < EPS && a[i] * x >= 0)
			{
				found = true;
				idx = &i;
			}
		}

		if (found)
		{
			printf("\n\n ������� � = %lf ������ : ��� a[%d]\n\n", x, *idx);
		}
		else
		{
			printf("\n\n ������� � = %lf �� ������ :\n\n", x);
		}
				
		printf("\n\n ����� �����\n");
	}

	return 0;

}


/*bool secSearch(double* a, int n, double x, int* idx)
{
	bool found = false;
	
	for (int i = 0; !found && i <= (n - 1); ++i)
	{
		if (fabs(a[i] - x) < EPS && a[i] * x >= 0)
		{
			found = true;
			idx =&i;
		}
	}

	return found;


}*/


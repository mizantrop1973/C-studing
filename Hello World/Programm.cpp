#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//�������� ����� � ���������� �������

void swap(double* x, double* y);
void bubbleSort(double* a, int n);
bool binSearch(double* a, int n, double x, int* idx);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	double* a = NULL;

	printf("\n ��������� ���������� ��������� ������� �� ����������� \n\n");

	while (true)
	{
		printf("\n �������  ����� ������� n :  ");
		if (scanf("%d", &n) < 1 || n <= 0)
			break;
		delete[] a;
		a = new double[n];

		for (i = 0; i < n; ++i)
		{
			a[i] = (double)(rand() % 100);
		}

		printf("\n ������� ������  :\n");
		for (i = 0; i < n; ++i)
		{
			printf("  %6.1lf  ", a[i]);
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
		printf("\n=================================\n");

		bubbleSort(a, n);
		printf(" ��������������� ������ :  \n");

		for (i = 0; i < n; ++i)
		{
			printf("  %6.1lf  ", a[i]);
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
		printf("\n=================================\n");

		while (true)
		{
			int idx = 0;
			double x;
			printf("\n ������� ������� ������ x = ");
			scanf_s("%lf", &x);
			
			bool found = binSearch(a, n, x, &idx);


			if (found)
			{
				printf("\n\n ������� � = %lf ������ : ��� a[%d]\n\n", x, idx);
			}
			else
			{
				printf("\n\n ������� � = %lf �� ������ \n\n", x);
			}
			printf("\n\n ����� �����\n");
		}
		delete[] a;
		return 0;

	}
}


void swap(double* x, double* y)
{
	double tmp = *x;
	*x = *y;
	*y = tmp;
}

void bubbleSort(double* a, int n) //����������� ����������� ���������� (�������)
{
	bool inverse = true;
	int k = 0;   //���������� ��������
	while (inverse)
	{
		inverse = false;
		for (int i = 0; i <= n - 1 - k; ++i) // ������ ������ ���������� ������������ ������� ������� � �����, �� ��� ���������
		{
			if (a[i] > a[i + 1]) // ���������� ��������� � ����� ������� n (������ n+1)
			{
				swap(&(a[i]), &(a[i + 1]));
				inverse = true;
			}
		}
		++k;  //  ���������� �������� �����������, n = (n * (n-1))/2
	}
}

void directSort(double* a, int n) //������ ����� (�������)
{
	for (int i = 0; i <= n - 1; ++i)
	{
		int m = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[m])
			{
				m = j;
			}
		}

		if (m != i)
		{
			swap(&(a[i]), &(a[m]));
		}
	}
}


bool binSearch(double* a, int n, double x, int* idx)
{
	bool found = false;
	if (n <= 0 || x <= a[0])
	{
		*idx = 0;
		return (n > 0 && x >= a[0]); // (���� - x = a[0}
	}
	else if (x > a[n - 1])
	{
		*idx = n;
		return false;
	}
	else
	{
		assert(n > 0 && x >= a[0] && x <= a[n - 1]);
		int beg = 0;
		int end = n - 1;
		assert(a[beg] < x && x <= a[end]);
		while (end - beg > 1)
		{
			int c = (end + beg) / 2;
			assert(beg < c&& c < end);
			if (a[c] < x)
			{
				beg = c;
			}
			else if (a[c] > x)
			{
				end = c;
			}
			else
			{
				// assert a[c] == x; - ���������� ������������ ����� �����������
				*idx = c;
				return true;
			}
		}
		assert(a[beg] < x && x <= a[end]);
		*idx = end;
		return (x >= a[end]);
	}
}


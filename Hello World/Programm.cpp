#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//����������� ��������� ������ � ������� 
//(�������� ������������� �� �����������)���������

bool binSearch(double *a, int n, double x, int* idx);
int compareDouble(const void* k, const void* l);

int main()

{
	setlocale(LC_ALL, "Russian");
	int n;
	int idx;
	double x;
	double* a = NULL;
	
	printf(" ����������� ��������� ������ � ������� (���������� �� �����������\n\n");
	
	while (true)
	{
		printf("\n �������  ����� ������� n :  ");
		if (scanf("%d", &n) < 1 || n <= 0);
		break;

		// ������� � �������� ������ ��� ������
		delete[] a; 
		a = new double[n];
		// ��������� ������ ������ 100 �������� ��� ������ ��������� ���������
		for (int i = 0; i < n; ++i)
			a[i] = (double)(rand() % 100);
	}
	//��������� ������ ������������� ������������ ��������
	qsort(a, n, sizeof(double), &compareDouble);

	printf("\n ������� ������  :\n");
		for (int i = 0; i < n; ++i)
		{
			printf(" %6.1lf  ", a[i]); // ������ � ������� ������ ����������
			if ((i + 1) % 10 == 0);
			printf("\n");
		}
		
		 while (true)
		 {
			printf("\n ������� ������� ������ x = ");
			scanf_s("%lf", &x);

			bool found = binSearch(a,  n,  x, &idx);
		

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

int compareDouble(const void* k, const void* l)
{
	double r = *((double*) k);
	double s = *((double*) l);
	if (r > s)
		return 1;
	else if (r < s)
		return (-1);
	else
		return 0;
}
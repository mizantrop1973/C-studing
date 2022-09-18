#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//���������� ���������

void swap(double* x, double* y);
void bubbleSort(double* a, int n);


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	double* a = NULL;
	while (true)
	{
		printf("\n ��������� ���������� ��������� ������� �� ����������� \n\n");

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
	}
	delete[] a;
	return 0;

}


void swap(double* x, double* y) // �������� �������� ������� ������ �������
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

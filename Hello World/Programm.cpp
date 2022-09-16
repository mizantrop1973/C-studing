#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//Организация последоватенльного поиска в массиве ИНВАРИАНТ

int secSearch(double *a, int n, double x);
const int N = 10000;
int n; 
double x;
double a[N];
const double EPS = 0.0000001;

int main()

{
	
	setlocale(LC_ALL, "Russian");
	printf(" Организация последоватенльного поиска в массиве\n\n");
	
	while (true)
	{
		printf("\n Введите  длину массива n < N = %d :  ", N);
		scanf_s("%d", &n);
		
		while (n > N || n <= 0)
		{
			printf("\n Длина массива менее 1(единицы) или выше допустимого (%d). Попробуйте еще раз\n", N);
			scanf_s("%d", &n);
		}
		printf("\n Введите масcив a длиной %d вещественных чисел (После каждого нажимать ENTER)  :\n", n);
		int i = 0;
				for (int i=0; i <= n - 1; i++)
		{
			printf(" a[%d] = ", i);

			scanf_s("%lf", &a[i]);
		}

		printf("\n Введен массив  :");
		for (i = 0; i <= n - 1; ++i)
		{
			printf("  %lf  ", a[i]); // пробел в формате печати обязателен
			//getchar(); getchar();
		}
		printf("\n\n Введите элемент поиска x = ");
		scanf_s("%lf", &x);

		int f = secSearch(a,  n,  x);// сделал все в функции main, так как с отдельной функцией возникли проблемы чтения переменной idx
		/*		bool found = false;

		for (int i = 0; !found && i <= (n - 1); ++i)
		{
			if (fabs(a[i] - x) < EPS && a[i] * x >= 0)
			{
				found = true;
				idx = &i;
			}
		}*/

		if (f >= 0)
		{
			printf("\n\n ОТВЕТ: Элемент х = %lf найден : Это a[%d]\n\n", x, f);
		}
		else
		{
			printf("\n\n ОТВЕТ: Элемент х = %lf не найден. \n\n", x);
		}
				
		printf("\n\n НОВЫЙ ПОИСК\n");
	}

	return 0;

}


int secSearch(double* a, int n, double x)
{
	int idx = -1;
	
	for (int i = 0; idx < 0 && i <= (n - 1); ++i)
	{
		if (fabs(a[i] - x) < EPS && a[i] * x >= 0)
		{
			idx = i;
		}
	}

	return idx;

}


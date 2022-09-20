#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//Быстрая соритировка

void swap(double* x, double* y);
//void bubbleSort(double* a, int n);
//void partition(double* a, int n, int* m);
//void quickSort(double* a, int n);
bool binSearch(double* a, int n, double x, int* idx);
void heapSort(double* a, int n);
void sieve (double *a, int n, int i);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	double* a = NULL;

	printf("\n ПРОГРАММА СОРТИРОВКИ ЭЛЕМЕНТОВ МАССИВА МЕТОДОМ КУЧИ (ПИРАМИДЫ) \n\n");

	while (true)
	{
		printf("\n Введите  длину массива n :  ");
		if (scanf("%d", &n) < 1 || n <= 0)
			break;
		delete[] a;
		a = new double[n];

		for (i = 0; i < n; ++i)
		{
			a[i] = (double)(rand() % 100);
		}

		printf("\n Имеется массив  :\n");
		for (i = 0; i < n; ++i)
		{
			printf("  %6.1lf  ", a[i]);
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
		printf("\n=================================\n");

		heapSort(a, n);
		printf(" Отсортированный массив :  \n");

		for (i = 0; i < n; ++i)
		{
			printf("  %4.1lf  ", a[i]);
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
		printf("\n=================================\n");

		while (true)
		{
			int idx = 0;
			double x;
			printf("\n Введите элемент поиска x = ");
			scanf_s("%lf", &x);
			
			bool found = binSearch(a, n, x, &idx);


			if (found)
			{
				printf("\n\n ОТВЕТ: Элемент х = %lf найден : Это a[%d]\n\n", x, idx);
			}
			else
			{
				printf("\n\n ОТВЕТ: Элемент х = %lf не найден \n\n", x);
			}
			printf("\n\n НОВЫЙ ПОИСК\n");
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


bool binSearch(double* a, int n, double x, int* idx)
{
	bool found = false;
	if (n <= 0 || x <= a[0])
	{
		*idx = 0;
		return (n > 0 && x >= a[0]); // (трюк - x = a[0}
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
				// assert a[c] == x; - сравнивать вещественные числа некорректно
				*idx = c;
				return true;
			}
		}
		assert(a[beg] < x && x <= a[end]);
		*idx = end;
		return (x >= a[end]);
	}
}

void heapSort(double* a, int n)
{
	//I-ый этап, построение пирамиды
	int k = n / 2;   // у  k нет детей (2k +1 == n+1 > n-1)
	while (k > 0)
	{
		--k;
		sieve(a, n, k); // Просеивание снизу справа - по окончанию будет построена ПИРАМИДА
	}

	// II-ой этап . Сортировка по пирамиде
	k = n;
	while(k>1)
	{
		--k;
		swap(&(a[0]), &(a[k]));
		sieve(a, k, 0);
	}
}

void sieve(double* a, int n, int i)
{
	while (true)
	{
		int s0 = 2 * i + 1;
		if (s0 >= n)
			break;
		int s1 = s0 + 1;
		int s = s0;
		if (s1<n && a[s1]> a[s0])
			s = s1;
		if (a[i] >= a[s])
			break;
		swap(&(a[i]), &(a[s]));
		i = s; //переходим вниз по дереву
	}
}

/*
void bubbleSort(double* a, int n) //оптимизация пузырьковой сортировки (наивный)
{
	bool inverse = true;
	int k = 0;   //количество проходов
	while (inverse)
	{
		inverse = false;
		for (int i = 0; i <= n - 1 - k; ++i) // каждый проход перемещает максимальный элемент массива в конец, мы его исключаем
		{
			if (a[i] > a[i + 1]) // количество сравнений в одном проходе n (иногда n+1)
			{
				swap(&(a[i]), &(a[i + 1]));
				inverse = true;
			}
		}
		++k;  //  количество проходов уменбшается, n = (n * (n-1))/2
	}
}

void directSort(double* a, int n) //прямой выбор (наивный)
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

void quickSort(double* a, int n)// быстрой сортировки
{
	if (n <= 1)
	{
		return;
	}
	else if (n == 2)
	{
		if (a[0] > a[1])
		{
			swap(&(a[0]), &(a[1]));
		}
		return;
	}
	// ИНВАРИАНТ ЦИКЛА
	//Отрезки массива а(0) - a(beg - 1) и а(beg+k) - a(n-1) отсортированы;
	// beg - начало неотсортированного отрезка длинной k;
	// ИНВАРИАНТ a[beg-1] <= a[i] <= a[beg+k];

	int beg = 0;
	int k = n;

	while (k > 1)
	{
		// выбираем медиану
		int m = k / 2;
		partition(a + beg, k, &m);
		int left = m;
		int right = k - 1 - left;

		if (left <= right)
		{
			quickSort(a + beg, left);
			beg += left + 1;
			k -= left + 1;
		}
		else // right <= left;
		{
			quickSort(a + beg + m + 1, right);
			// beg остается прежним
			k -= right + 1;
		}
	}
}

void partition(double* a, int n, int* m)
{
	//сначала перемещаем медиану в начало массива
	if (*m != 0)
		swap(&(a[0]), &(a[*m]));
	double x = a[0];
	//иннвариант 
	// a[0] == x - медиана
	// a[1], a[2],...a[i] <= x
	// a[j]....a[n-1] >= x

	int i = 0; int j = n;

	while (j - i > 1)
	{
		bool changed = false;
		if (a[i + 1] <= x) // ЗДЕСЬ была ошибка, которая проявлялась при утверждении assert - был знак строго меньше.
		{
			++i; changed = true;
		}
		if (j - 1 > i && a[j - 1] >= x)
		{
			--j; changed = true;
		}
		if (!changed)
		{
			assert(j - i > 1 && a[i + 1] > x && a[j - 1] < x); // !!!!!  в лекции было строго больше и меньше, но почему то в этом случае происходит сбой
			++i, --j;
			swap(&(a[i]), &(a[j]));
		}
	}
	if (i > 0)
	{
		swap(&(a[0]), &(a[i]));
	}
	*m = i;

}
*/



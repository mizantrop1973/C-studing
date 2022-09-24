#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



bool binSearch(double* a, int n, double x, int* idx);
//void mergeSortRecursvely(double* a, int n, double* b, int* arrayIdx);
void mergeSortRecursvely(double* a, int n, double* b, int res0, int res1, int* arroyIdx);
void copyArray (double* b, double* a, int n);
void mergeSort(double* a, int n);
void merge(double* a, int n,double* b, int m, double* c);
//void heapSort(double* a, int n);
//void sieve (double *a, int n, int i);
//void bubbleSort(double* a, int n);
//void partition(double* a, int n, int* m);
//void quickSort(double* a, int n);
void swap(double* x, double* y);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	double* a = NULL;

	printf("\n ��������� ���������� ��������� ������� ������� ������� (���������� ������������� �����������) \n\n");

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
			printf("  %4.1lf  ", a[i]);
			if ((i + 1) % 10 == 0)
				printf("\n");
		}
		printf("\n=================================\n");

		mergeSort(a, n);
		printf(" ��������������� ������ :  \n");

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
			printf("\n ������� ������� ������ x = ");
			scanf_s("%lf", &x);
			
			bool found = binSearch(a, n, x, &idx);


			if (found)
			{
				printf("\n\n �����: ������� � = %lf ������ : ��� a[%d]\n\n", x, idx);
			}
			else
			{
				printf("\n\n �����: ������� � = %lf �� ������ \n\n", x);
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

void mergeSort(double* a, int n)
{
	if (n <= 1)
		return;
	if (n == 2)
	{
		if (a[0] > a[1])
		{
			swap(&(a[0]), &(a[1]));
		}
		return;
	}
	double* b = new double[n];

	double* src = a;
	double* dst = b;
	int len = 1;

	while (len < n)
	{
		//��������� ������ src  ������ �� ���� ����������� ����� len (��������� ����� ���� ������)
		// ������ ��������� ����������
		int i = 0; //������ ������ ���� �����������
		while (i < n - len)
		{
			int len2 = len;
			if (i + len + len2 > n)
			{
				len2 = n - (i + len);
			}
			merge(src + i, len, src + i + len, len2, dst + i);
			i += len + len2;
		}
		if (i < n)
			copyArray(src + i, dst + i, n - i);
		len *= 2;
		//������ ������� �������� � ����������
		double* tmp = src;
		src = dst;
		dst = tmp;
	}
	if (src != a)
		copyArray(b, a, n);
	delete[] b;



	/*
	int arrayIdx;
	int res0; int res1; //��������� ���������� ���� � ������� � ���� � ������� b
	res0 = 0; res1 = 0;
	mergeSortRecursvely(a, n, b, res0, res1, &arrayIdx);

	if (arrayIdx != 0)
	copyArray(b, a, n);
	delete[] b;
	*/
}


void mergeSortRecursvely(double* a, int n, double* b, int res0, int res1, int* arrayIdx)
{
	*arrayIdx = 0;
	if (n <= 1)
		return;
	
	

	//assert(n > 2);

	int k = n / 2; //��������� ������ �� 2 �����, k - ������ ������ ��������.

	//int res0=0; int res1 = 0; //��������� ���������� ���� � ������� � ���� � ������� b

	mergeSortRecursvely(a, k, b, res0, res1, &res0);
	++res0;

	mergeSortRecursvely(a+k, n-k, b+k, res0, res1, &res1);
	++res1;

	if (res0 % 2 != res1 % 2)
	{
		if (res0 % 2 != 0)
		{
			copyArray(b + k, a + k, n - k);
		}
		else
		{
			copyArray(a + k, b + k, n - k);
		}
	}
	if (res0%2 != 0)
	{
		merge(a, k, a + k, n - k, b);
	}
	else
	{
		merge(b, k, b + k, n - k, a);
	}
	*arrayIdx = res0 % 2;
}


void copyArray(double* b, double* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = b[i];
}

void merge(double* a, int n, double* b,  int m, double* c)
{
	int i = 0; 
	int j = 0;
	int k = 0;
	while (i < n && j < m)
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i]; ++i;
		}
		else
		{
			c[k] = b[j]; ++j;
		}
		++k;
	}
	while (i < n)
	{
		c[k] = a[i]; ++i; ++k;
	}
	while (j < m)
	{
		c[k] = b[j]; ++j; ++k;
	}
}
/*
void heapSort(double* a, int n)
{
	//I-�� ����, ���������� ��������
	int k = n / 2;   // �  k ��� ����� (2k +1 == n+1 > n-1)
	while (k > 0)
	{
		--k;
		sieve(a, n, k); // ����������� ����� ������ - �� ��������� ����� ��������� ��������
	}

	// II-�� ���� . ���������� �� ��������
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
		i = s; //��������� ���� �� ������
	}
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

void quickSort(double* a, int n)// ������� ����������
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
	// ��������� �����
	//������� ������� �(0) - a(beg - 1) � �(beg+k) - a(n-1) �������������;
	// beg - ������ ������������������ ������� ������� k;
	// ��������� a[beg-1] <= a[i] <= a[beg+k];

	int beg = 0;
	int k = n;

	while (k > 1)
	{
		// �������� �������
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
			// beg �������� �������
			k -= right + 1;
		}
	}
}

void partition(double* a, int n, int* m)
{
	//������� ���������� ������� � ������ �������
	if (*m != 0)
		swap(&(a[0]), &(a[*m]));
	double x = a[0];
	//���������� 
	// a[0] == x - �������
	// a[1], a[2],...a[i] <= x
	// a[j]....a[n-1] >= x

	int i = 0; int j = n;

	while (j - i > 1)
	{
		bool changed = false;
		if (a[i + 1] <= x) // ����� ���� ������, ������� ����������� ��� ����������� assert - ��� ���� ������ ������.
		{
			++i; changed = true;
		}
		if (j - 1 > i && a[j - 1] >= x)
		{
			--j; changed = true;
		}
		if (!changed)
		{
			assert(j - i > 1 && a[i + 1] > x && a[j - 1] < x); // !!!!!  � ������ ���� ������ ������ � ������, �� ������ �� � ���� ������ ���������� ����
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



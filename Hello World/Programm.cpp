#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// �������� ������������� ���������

// ������� 1 ��������� �������� ������� �� �����������, ������� �������, ����������� ��
//           ����� ������ O(nlogn) (����������) + �������� ����� ���������
//    

void elementsSet(int* a, int n, int* m);

//��������������� �������
void swap(int* x, int* y);
void heapSort(int* a, int n);
void sieve(int* a, int n, int i);




int main()

{
	FILE* in = fopen("C:/Users/�������/Documents/input.txt", "r");
	if (in == NULL)
	{
		perror("Can not open file");
		return (-1);
	}
	int n = 0;
	int x;

	while (fscanf(in, "%d", &x) == 1)
	{
		++n;
	}
	printf("\n  Array has %d elements \n", n);
	if (n <= 0)
	{
		fprintf(stderr, "epmty input file \n");
	}

	rewind(in);

	int* a = new int [n];
	int m = 0;
	while (m < n)
	{
		if (fscanf(in, "%d", &x) < 1)
		{
			perror("read error");
			return(-1);
		}
		a[m] = x; ++m;
	}
	fclose(in);

	assert(n == m && n > 0);
	int k;
//	printf("  Enter the number of shift positions k: ");
//	scanf("%d", &k);


	elementsSet(a, n, &m);

	//������ ���������
	FILE* out = fopen("C:/Users/�������/Documents/output.txt", "w");
	if (out == NULL)
	{
		perror("cannot open output file");
		return(-1);
	}

	for (int i = 0; i < m; ++i)
	{
		fprintf(out, " %d", a[i]);
		if ((i+1)%10==0)
		{
			fprintf(out, "\n");
		}
	}

	fclose(out);
	return 0;
}

//�������� �������
void elementsSet(int* a, int n, int* m)
{
	heapSort(a, n);
	int k = 0; // ���������� ��������� ��������� � ������������� ����� �������
	for (int i = 0; i < n; ++i)
	{
		if (k == 0 || a[i] > a[k - 1])
		{
			if (i > k)
				a[k] = a[i];
			++k;
		}
	}
	*m = k;
}


// ��������������� �������
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


void heapSort(int* a, int n)
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
	while (k > 1)
	{
		--k;
		swap(&(a[0]), &(a[k]));
		sieve(a, k, 0);
	}
}

void sieve(int* a, int n, int i)
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

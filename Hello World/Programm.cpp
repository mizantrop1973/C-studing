#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// ����������� ����� ��������� ������� �� � ������� ������ (��������� �� ������)

// 
// 2) ��������� �� ������ (������������ ������� �������� �� k ������� ����� ����� �������) ,
//    ����� ������ d = ��� (k, n)

void shiftk(int* a, int n, int k);
int gcd(int m, int n);



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
	printf("  Enter the number of shift positions k: ");
	scanf("%d", &k);


	shiftk(a, n, k);

	//������ ���������
	FILE* out = fopen("C:/Users/�������/Documents/output.txt", "w");
	if (out == NULL)
	{
		perror("cannot open output file");
		return(-1);
	}

	for (int i = 0; i < n; ++i)
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

void shiftk(int* a, int n, int k)
{	
	k %= n; // ������� �� ������� �� n - ����������� ��� ��� k > n, ��� � ��� k < n;
	if (k == 0)
		return;
	int nod = gcd(n, k);
	int i = 0;
	while (i < nod)
	{
		// �������� ������ �������� i
		int x = a[i]; // ��������� ������� ������
		int j = i + k;
		if (j >= n)
			j -= n;
		while (j != i)    //����� �������� �����������  - 3 ��� ������� �������� ������, �����  n
		{				  //����� n ��������� ������ ������, �� ���� 3n �����������
			int y = a[j];
			a[j] = x;
			x = y;
			j += k;
			if (j >= n)
				j -= n;
		}
		a[i] = x;

		++i; // ��������� � ��������� ������
	}
}

int gcd(int m, int n)
{
	int a = m;
	int b = n;

	while (b != 0)
	{
		int r = a % b;
		a = b; b = r;
	}
	//����������� n=0 � ��� (m,n)=���(m0,n0)
	return a;
}
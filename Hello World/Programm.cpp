#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <cassert>

//��� ����������� �������� ������� ���������

int extgcd(int m, int n, int* u, int* v);

int main()

{
	int m, n;
	setlocale(LC_ALL, "Russian");
	printf(" ����������� �������� ������� (���������)\n\n");
	
	while (true)
	{
		
		printf("\n ������� 2 ����� m � n : \n");
		printf("\n m = ");
		scanf_s("%d", &m);
		printf("\n n = ");
		scanf_s("%d", &n);
		
		int u, v;
		int d = extgcd(m, n, &u, &v);
		printf("\n ��� = %d  u = %d  v = %d\n\n\n", d, u, v);
				
		printf("\n ����� ������\n");
	}

	return 0;

}

int extgcd(int m, int n, int* u, int* v)
{
	int a = m;
	int b = n;
	int u1 = 1; int v1 = 0; 
	int u2 = 0; int v2 = 1;
	assert(a == u1 * m + v1 * n && b == u2 * m + v2 * n);
	//����������� 1 ���(a, b) = ���(m, n);
    //����������� 2 int a = u1 * m + v1 * n;
	//����������� 3 int b = u2 * m + v2 * n;
	while (b != 0)
	{
		int q = a / b; // � �� �������� � ������ ������� �������� � ����� ����� htpekmnfnf
		int r = a % b;
		a = b; b = r;
		int tmp = u2; u2 = u1 - q * u2;
		u1 = tmp;
		tmp = v2;v2 = v1 - q * v2;
		v1 = tmp;
	}
	*u = u1; *v = v1;

	return a;

}

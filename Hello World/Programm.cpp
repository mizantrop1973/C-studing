#include <stdio.h>

#include <locale.h>
#include <math.h> 

//��� ����������� �������� �������
int gcd(int m, int n);
int gcd1(int m, int n);
int extgcd(int m, int n, int* u, int* v);


int main()

{
	setlocale(LC_ALL, "Russian");
	int m, n;
	printf("������� 2 �����:\n");
	scanf_s("%d%d", &m, &n);
	int d = gcd(m, n);
	printf("���=%d\n", d);

	d = gcd1(m, n);
	printf("���1=%d\n", d);

	int u, v;
	d = extgcd(m, n, &u, &v);
	printf("���2=%d  u=%d  v=%d\n", d, u, v);
	return 0;
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
int gcd1(int m, int n)
{
	if (n == 0)
		return m;
	int r = m % n;
	// ��� (m , n) = ��� (n ,r)
	return gcd1(n, r);
}
int extgcd(int m, int n, int* u, int* v)
{
	if (n == 0)
	{
		*u = 1; *v = 0;
		return m;
	}
	int q = m / n; int r = m % n;
	int u1, v1;
	int d = extgcd(n, r, &u1, &v1);
	*u = v1; *v = u1 - v1 * q;


	//��� (m , n) = ��� (n ,r)
	return d;

}




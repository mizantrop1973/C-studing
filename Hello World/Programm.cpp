#include <stdio.h>
#include <locale.h>
#include <math.h> 



//��� ���� ����� �����
int gcd1(int m, int n);
int m, n;

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("������� m:\n");
	scanf_s("%d", &m);
	printf("������� n:\n");
	scanf_s("%d", &n);
	m=gcd1(m, n);
	printf(" ��� m � n = %d\n ", m);
	return 0;

}
int gcd1(int m, int n)
{
	if (n == 0)
		return m;
	int r = m % n;
	return gcd1(n, r);
	/*while (n != 0)
	{
		int r = m % n;
		m = n; n = r;
	}
	//����������� n=0 � ��� (m,n)=���(m0,n0)
	return m;*/
}


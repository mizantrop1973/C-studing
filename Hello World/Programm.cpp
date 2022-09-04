#include <stdio.h>
#include <locale.h>
#include <math.h> 



//НОД двух целых чисел
int gcd(int m, int n);
int m, n;

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите m:\n");
	scanf_s("%d", &m);
	printf("Введите n:\n");
	scanf_s("%d", &n);
	m=gcd(m, n);
	printf(" НОД m и n = %d\n ", m);
	return 0;

}
int gcd(int m, int n)
{
	while (n != 0)
	{
		int r = m % n;
		m = n; n = r;
	}
	//Утверждение n=0 и НОД (m,n)=НОД(m0,n0)
	return m;
}


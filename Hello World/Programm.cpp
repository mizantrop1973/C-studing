#include <stdio.h>
#include <locale.h>
#include <math.h> 

//Разложение числа  F5 неа множители


int main()

{
	setlocale(LC_ALL, "Russian");
	long long n, d, k;
	printf("Введите n:\n n=");
	scanf_s("%lld", &n);
	printf("Разложение на множители\n");

	
	d = 2; k = 0;

	while (d <= n)
	{
		if(n%d==0)
		{
			printf("%lld  ", d);
			++k;
			n /= d;
		}
		else
		{
			if (d == 2)
				++d;
			else
				d += 2;
		}
	}
	printf("\n");
	if (k == 1)
		printf("Простое\n");

	return 0;
}
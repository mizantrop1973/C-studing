#include <stdio.h>
#include <locale.h>
#include <math.h> 

//Разложение числа неа множители

//Integer factorization


int main()

{
	setlocale(LC_ALL, "Russian");
	int n, d, k;
	printf("Введите n:\n n=");
	scanf_s("%d", &n);
	
	d = 2; k = 0;

	while (d <= n)
	{
		if(n%d==0)
		{
			printf("%d  ", d);
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
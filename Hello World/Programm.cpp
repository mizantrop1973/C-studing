#include <stdio.h>
#include <locale.h>
#include <math.h> 

//Печать n простых чисел МЕТОД Эротосфена (квадратичное решето)
//Нахождение простых чисел на отрезке 0 - (N-1)




int main()

{
	setlocale(LC_ALL, "Russian");
	int n, p, i;
	printf(
		"РЕШЕТО ЭРОТОСФЕНА. Вычисление всех простых чисел\n"
		"на отрезке от 0 до N\n"
	);
	printf("Введите n:\n n=");
	scanf_s("%d", &n);
	bool* a = new bool[n + 1];
	for (i = 0; i <= n; ++i)
		a[i] = true;

	a[0] = false;
	a[1] = false;
	a[2] = true;

	p = 2;
	while (p < n)
	{
		i = p + p;
		while (i <= n)
		{
			a[i] = false;
			i += p;
		}
		++p;
		while (p <= n && !a[p])
			++p;
	}

	int numPrimes = 0;
	for (i = 0; i <= n; ++i)
	{
		if (a[i])
		{
			if (numPrimes > 0)
			{
				if (numPrimes % 10 == 0)
				{
					printf("\n");
				}
				else
				{
					printf("  ");
				}
			}
			printf("%d", i);
			++numPrimes;
		}
	}

	if (numPrimes % 10 != 0)
	{
		printf("\n");
		printf("Количество простых чисел = %d\n", numPrimes);
	}

	return 0;
		
}
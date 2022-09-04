#include <stdio.h>
#include <locale.h>
#include <math.h> 

//Разложение числа на множители самостоятельно

//Integer factorization myself


int main()

{
	setlocale(LC_ALL, "Russian");
	int n, d, k;
	printf("Введите n:\n n = ");
	scanf_s("%d", &n);
	d = 2;
	k = 0;
	while (n % d == 0)
	{
		n = n / d;
		printf("%d  \n", d);
		++k;
	}
	d = 3;
	for (d = 3; n / d >= 1; d += 2)
	{
		while (n % d == 0)
		{
			n = n / d;
			printf("%d  \n", d);
			++k;
		}

	}
	if (k == 1)
	{
		printf("n - простое число\n");
	}


	return 0;
}
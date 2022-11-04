#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// ѕолучаем биномиальные коэффициенты

// 
//  

void binom(int* a, int n);


int main()

{
	int* a = NULL;
	while (true)
	{
		int n;
		printf("  n: ");
		if (scanf("%d", &n) < 1 || n == 0)
			break;
		delete[] a;
		a = new int[n + 1];

		binom(a, n);

		for (int i = 0; i <= n; ++i)

			printf("  %d", a[i]);
		printf("\n");

	}
}

//ќ—Ќќ¬Ќјя ‘”Ќ ÷»я
void binom(int* a, int n)
{
	a[0] = 1; //   с(0;0)
	for (int k = 1; k <= n; ++k) //вычисл€ем коэффициенты с(k;i)
	{
		int prev = 0;
		for (int i = 0; i <= k; ++i)
		{
			int tmp = a[i];
			if (i < k)
			{
				a[i] += prev;
				prev = tmp;
			}
			else
			{
				a[i] = prev;
			}
		}
	}
}



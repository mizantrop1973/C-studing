#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// Циклический сдвиг элементов массива на К позиций вправо (разбиение на орбиты)

// 
// 2) разбиваем на орбиты (перестановка первого элемента на k позиций вдоль всего массива) ,
//    число циклов d = НОД (k, n)

void shiftk(int* a, int n, int k);
int gcd(int m, int n);



int main()

{
	FILE* in = fopen("C:/Users/Дмитрий/Documents/input.txt", "r");
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

	//выдаем результат
	FILE* out = fopen("C:/Users/Дмитрий/Documents/output.txt", "w");
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
	k %= n; // остаток от деления на n - справедливо как для k > n, так и для k < n;
	if (k == 0)
		return;
	int nod = gcd(n, k);
	int i = 0;
	while (i < nod)
	{
		// проходим орбиту элемента i
		int x = a[i]; // начальный элемент орбиты
		int j = i + k;
		if (j >= n)
			j -= n;
		while (j != i)    //число операций копирования  - 3 для каждого элемента орбиты, всего  n
		{				  //всего n элементов каждой орбиты, то есть 3n копирований
			int y = a[j];
			a[j] = x;
			x = y;
			j += k;
			if (j >= n)
				j -= n;
		}
		a[i] = x;

		++i; // переходим к следующей орбите
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
	//Утверждение n=0 и НОД (m,n)=НОД(m0,n0)
	return a;
}
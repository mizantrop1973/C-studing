#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// Циклический сдвиг элементов массива на К позиций вправо (инвертирование блоков)

// два способв
// 1) инвертируем левый блок n-k , инвертируем правый блок k, инвертируем весь массив длинны n

void reverse(int* a, int n);
void shiftk(int* a, int n, int k);



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
	printf("Array has %d elements \n", n);
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
	printf("Enter the number of shift positions k:");
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
		fprintf(out, "%d", a[i]);
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
	reverse(a, n - k);// скорость работы (n - k)/2 
	reverse(a + n - k, k); //скорость работы n/2 
	reverse(a, n); //скорость работы  n/2 
	// ВСЕГО примерно n перестановок (обменов)
}

void reverse(int* a, int n)
{
	if (n <= 1)
		return;
	int i = 0; int j = n - 1;

	while (i < j)
	{
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		++i; --j;

		// каждый обмен влечет три операции копирования, итого 3n
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// —двиг элементов массива вправо на одну позицию

// два варианта:
//1) входной массив содержит на первом месте число элементов массива, а потом идут элементы массива
//2) входной файл содержит только элементы массива

//rewind(f)  - перемотка файла на начало
//fseek(f, 0, SEEK_SET) - смещение на (второй аргумент) от начала файла  (SEEK_SET, SEEK_CUR, SEEK_END)

void shift(int* a, int n);

int main()

{
	FILE* in = fopen("C:/Users/ƒмитрий/Documents/input.txt", "r");
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

	shift(a, n);

	//выдаем результат
	FILE* out = fopen("C:/Users/ƒмитрий/Documents/output.txt", "w");
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

void shift(int* a, int n)
{
	if (n <= 0)
		return;
	int last = a[n - 1];

	for (int i = n - 1; i > 0; --i)
	{
		a[i] = a[i - 1];
	}
	a[0] = last;
}
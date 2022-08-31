#include <stdio.h>
#include <locale.h>
#include <math.h> 

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k;
	//int k = 1;
	printf("¬ведите начальное число k=");
	scanf_s("%d", &k);
	printf("¬ведите конечное число n=");
	scanf_s("%d", &n);
	for (k=k; k<=n; k=k+1)
	{
		printf("%d  %d\n", k, k * k);
	}
	return 0;
}
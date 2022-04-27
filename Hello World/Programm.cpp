#include <stdio.h>
#include <locale.h>
#include <math.h> 

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 20;
	int k = 1;
	for (k=1; k<=20; k=k+1)
	{
		printf("%d  %d\n", k, k * k);
	}
	return 0;
}
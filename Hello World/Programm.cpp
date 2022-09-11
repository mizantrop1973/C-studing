#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 


int main()

{
	setlocale(LC_ALL, "Russian");
	
	double a, t, p=0;
	printf("¬ведите t : \n");
	scanf("%lf", &t);
	printf("¬ведите коэф-ты многочлена (по убыванию) : \n");
	while (scanf("%lf", &a) == 1)
	{   
		p = p * t + a;
	}
	printf("«начение многочлена в  точке t  = %lf\n", p);

		return 0;
}

		

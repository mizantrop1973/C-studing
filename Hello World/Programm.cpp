#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 


int main()

{
	setlocale(LC_ALL, "Russian");

	double a, t, p = 0, dp = 0;
	printf("Введите t : \n");
	scanf("%lf", &t);
	printf("Введите коэф-ты многочлена (через пробел, по убыванию). Конец ввода обозначте решёткой << # >> и нажмите ENTER : \n");
	//при вводе с клавиатуры для лклнчания ввода использовать символ "#";
	while (scanf("%lf", &a) == 1)
	{
		dp = dp * t + p;
		p = p * t + a;
	}
	printf("Значение многочлена в  точке t  = %lf\n", dp);

	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 


int main()

{
	setlocale(LC_ALL, "Russian");
	printf("Значение среднеарифметического последовательности \n");
	double a, p = 0, s = 0.;
	int l = 0;

	printf("Введите коэф-ты многочлена (через пробел, по убыванию). Конец ввода обозначте решёткой << # >> и нажмите ENTER : \n");
	//при вводе с клавиатуры для лклнчания ввода использовать символ "#";
	while (scanf("%lf", &a) == 1)
	{
		s = s + a;
		l = l + 1;
		p = s / l;
	}
	printf("Значение среднеарифметического последовательности p = %lf\n", p);

	return 0;
}

		

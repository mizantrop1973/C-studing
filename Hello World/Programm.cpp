#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 


int main()

{
	setlocale(LC_ALL, "Russian");
	printf("�������� ��������������������� ������������������ \n");
	double a, p = 0, s = 0.;
	int l = 0;

	printf("������� ����-�� ���������� (����� ������, �� ��������). ����� ����� ��������� �������� << # >> � ������� ENTER : \n");
	//��� ����� � ���������� ��� ��������� ����� ������������ ������ "#";
	while (scanf("%lf", &a) == 1)
	{
		s = s + a;
		l = l + 1;
		p = s / l;
	}
	printf("�������� ��������������������� ������������������ p = %lf\n", p);

	return 0;
}

		

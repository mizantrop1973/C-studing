#include <stdio.h>
#include <locale.h>
#include <math.h> 

//���������� �����  F5 ��� ���������


int main()

{
	setlocale(LC_ALL, "Russian");
	long long n, d, k;
	printf("������� n:\n n=");
	scanf_s("%lld", &n);
	printf("���������� �� ���������\n");

	
	d = 2; k = 0;

	while (d <= n)
	{
		if(n%d==0)
		{
			printf("%lld  ", d);
			++k;
			n /= d;
		}
		else
		{
			if (d == 2)
				++d;
			else
				d += 2;
		}
	}
	printf("\n");
	if (k == 1)
		printf("�������\n");

	return 0;
}
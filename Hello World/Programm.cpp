#include <stdio.h>
#include <locale.h>
#include <math.h> 

//���������� ����� �� ��������� ��������������

//Integer factorization myself


int main()

{
	setlocale(LC_ALL, "Russian");
	int n, d, k;
	printf("������� n:\n n = ");
	scanf_s("%d", &n);
	d = 2;
	k = 0;
	while (n % d == 0)
	{
		n = n / d;
		printf("%d  \n", d);
		++k;
	}
	d = 3;
	for (d = 3; n / d >= 1; d += 2)
	{
		while (n % d == 0)
		{
			n = n / d;
			printf("%d  \n", d);
			++k;
		}

	}
	if (k == 1)
	{
		printf("n - ������� �����\n");
	}


	return 0;
}
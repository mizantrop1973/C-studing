#include <stdio.h>
#include <locale.h>
#include <math.h> 

//��� ���� ����� �����


int main()

{
	int gcd(int m, int n)
	{
		while (n != 0)
		{
			int r = m % n;
			m = n; n = r;
		}
		//����������� n=0 � ��� (m,n)=���(m0,n0)
		return m;
	}
	
	return 0;
}
#include <stdio.h>
#include <locale.h>
#include <math.h> 

//��� ���� ����� ����� ����������


int main()

{
	
	
	return 0;
}

int gcd1(int m, int n)
{
	if (n == 0)
		return m;
	int r = m % n;
	// ��� (m , n) = ��� (n ,r)
	return gcd1(n, r);

}


		/* while (n != 0)
		{
			int r = m % n;
			m = n; n = r;
		}
		����������� n=0 � ��� (m,n)=���(m0,n0)
		return m;*/
	
#include <stdio.h>
#include <locale.h>
#include <math.h> 

//НОД двух целых чисел


int main()

{
	int gcd(int m, int n)
	{
		while (n != 0)
		{
			int r = m % n;
			m = n; n = r;
		}
		//Утверждение n=0 и НОД (m,n)=НОД(m0,n0)
		return m;
	}
	
	return 0;
}
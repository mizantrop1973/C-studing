#include <stdio.h>
#include <locale.h>
#include <math.h> 

//НОД двух целых чисел РЕКУРСИВНО


int main()

{
	
	
	return 0;
}

int gcd1(int m, int n)
{
	if (n == 0)
		return m;
	int r = m % n;
	// НОД (m , n) = НОД (n ,r)
	return gcd1(n, r);

}


		/* while (n != 0)
		{
			int r = m % n;
			m = n; n = r;
		}
		Утверждение n=0 и НОД (m,n)=НОД(m0,n0)
		return m;*/
	
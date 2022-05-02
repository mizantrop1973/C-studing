#include <stdio.h>
#include <locale.h>
#include <math.h> 


bool prime(int n);

int main ()

{
	setlocale(LC_ALL, "Russian");
	int n, k, p;
	printf ("¬ведите n:\n n=");
	scanf_s ("%d", &n);

	k = 0;
	p = 2;
	printf("%d  ", p);
	++k; //number of primes

	p = 3;
	while (k < n)
	{
		if (prime(p))
		{
			printf("%d  ", p);
			++k;
			if (k % 10 == 0)
				printf("\n");
		}
		p += 2;
	}
	printf("\n");

	return 0;
}

bool prime(int p)
{
	if (p < 2)
		return false;     //0, 1 are nor prime
	else if (p == 2)
		return true;      // 2 is prime
	else if (p % 2 == 0)
		return false;     // p is even

	// p.1 is odd;
	int d = 3;
	while (d * d <= p)
	{
		if (p % d == 0)
		{
			return false;
		}
		d += 2;
	}
	return true;
}
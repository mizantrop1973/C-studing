#include <stdio.h>
#include <locale.h>
#include <math.h> 

//ѕечать n простых чисел путем провенрки делением 
// на найденные простые числа

const int MAX_PRIMES = 100000;
static int primes[MAX_PRIMES];
static int numPrimes = 0;

int main()

{
	setlocale(LC_ALL, "Russian");
	int n, p;
	printf("¬ведите n:\n n=");
	scanf_s("%d", &n);
	if (n > MAX_PRIMES)
		n = MAX_PRIMES;

	primes[0] = 2;
	++numPrimes;

	p = 3;
	while (numPrimes < n)
	{
		bool prime = true;
		for (int i = 0; prime && i < numPrimes; ++i)
		{
			int d = primes[i];
			if (d * d > p)
				break;
			else if (p % d == 0)
				prime = false;
		}
		if (prime)
		{
			primes[numPrimes] = p;
			++numPrimes;
		}
		p += 2;
	}

	for (int i = 0; i < numPrimes; ++i)
	{
		printf("%d  ", primes[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}
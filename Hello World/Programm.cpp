#include <stdio.h>
#include <locale.h>
#include <math.h> 
#include <assert.h>


double f(double);
double root(double a, double b, double eps);


int main()
{
	setlocale(LC_ALL, "Russian");
	double x = root (1., 2., 0.000001);
	printf("x=%lf\n", x);
	return 0;
}

double f(double x)
{
	return x * x * x - x - 1.;
}

double root (double a, double b, double eps)
{
	double fa = f(a);
	double fb = f(b);

	int sa, sb; // знак функции

	if (fa > 0.)
	{
		sa = 1;
	}

	else if (fa < 0)
	{
		sa = -1;
	}
	else
	{
		return a;
	}

	if (fb > 0.)
	{
		sb = 1;
	}

	else if (fb < 0)
	{
		sb = -1;
	}
	else
	{
		return b;
	}

	assert(sa * sb <= 0);

	while (fabs(b - a) > eps)
	{
		double c = (a + b) / 2.;
		double fc = f(c);
		int sc;
		if (fc > 0.)
		{
			sc = 1;
		}

		else if (fc < 0)
		{
			sc = -1;
		}
		else
		{
			return c;
		}

		if (sa * sc <= 0)
		{
			b = c;
			sb = sc;
		}
		else
		{
			a = c;
			sa = sc;
		}
	}
	return (a + b) / 2.;
}
	
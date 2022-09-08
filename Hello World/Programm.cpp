#include <stdio.h>
#include <locale.h>
#include <math.h> 

double sum(FILE* f);

int main()

{
	setlocale(LC_ALL, "Russian");
	FILE* in, * out;
	fopen_s (&in, "c:/Users/�������/Documents/input.txt", "r");
	if (in == NULL)
	{
		perror("�� ������� �������� ����\n");
		return(-1);
	}
	double s = sum(in);
	fclose(in);

	fopen_s(&out, "c:/Users/�������/Documents/output.txt", "w");
	if (out == NULL)
	{
		perror("�� ������� �������� ����\n");
		return(-1);
	}
	fprintf_s(out, "% lf\n", s);
	fclose(out);
	return 0;
}
double sum (FILE* f)
{
	double s = 0.;
	double a;
	while (fscanf_s(f, "%lf", &a) == 1)
	{
		s += a;
	}
	return s;
	
}

		

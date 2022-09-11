#include <stdio.h>
#include <locale.h>
#include <math.h> 

double max(FILE* f);

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
	double m = max(in);
	fclose(in);

	fopen_s(&out, "c:/Users/�������/Documents/output.txt", "w");
	if (out == NULL)
	{
		perror("�� ������� �������� ����\n");
		return(-1);
	}
	fprintf_s(out, "�������� = % lf\n", m);
	fclose(out);
	return 0;
}
double max (FILE* f)
{
	double m = -1e+30;
	double a;
	while (fscanf_s(f, "%lf", &a) == 1)
	{
		if (a > m)
		m = a;		
	}
	return m;
	
}

		

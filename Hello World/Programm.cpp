#include <stdio.h>
#include <locale.h>
#include <math.h> 

double sum(FILE* f);

int main()

{
	setlocale(LC_ALL, "Russian");
	FILE* in, * out;
	fopen_s (&in, "c:/Users/Дмитрий/Documents/input.txt", "r");
	if (in == NULL)
	{
		perror("Не удалось прочесть файл\n");
		return(-1);
	}
	double s = sum(in);
	fclose(in);

	fopen_s(&out, "c:/Users/Дмитрий/Documents/output.txt", "w");
	if (out == NULL)
	{
		perror("Не удалось прочесть файл\n");
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

		

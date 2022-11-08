#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h> 
#include <cassert>



// запись числа X  в двоичной и шестнадцатиричной форме

// 
//  

void binary(int n0, char* t);
void hexadecimal(int n0, char* t1);
const char HEXDIGITS[17] = "0123456789abcdef";
const char BINARYDIGITS[4] = "01";
int main()

{
	char t[128];
	char t1[32];
	int n0;
	printf("  Writing the number N in binary and hexadecimal form \n\n");

	while (true)
	{
		printf("  Enter N: ");
		int res = scanf("%d", &n0);
		if (res <= 0 || n0 == 0)
			break;

		binary(n0, t);
		printf("  binary form of N = %d is  %s \n\n", n0, &t);
		

		hexadecimal(n0, t1);
		printf("  hexadecimal form of N = %d is  %s \n\n\n", n0, &t1);
		printf("  New representation\n\n");

	}
}

//BINARY REPRESENTATION
void binary(int n0, char* t)
{
	int n = n0;
	
	int i = sizeof(int) * 8;
	t[i] = 0;
	
	while (i > 0)
	{
		--i;
		int d = (n & 1);
		n >>= 1;
		t[i] = BINARYDIGITS[d];
	}
}

//HEXADECIMAL REPRESENTATION
void hexadecimal(int n0, char* t1)

{
	int n = n0;
	
	int i = sizeof(int)*2;
	t1[i] = 0;
		while (i > 0)
	{
		--i;
		int d = (n & 0xf);
		n >>= 4;
		t1[i] = HEXDIGITS[d];
		
	}
}

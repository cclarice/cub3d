#include <math.h>
#include <stdio.h>

int abs(int c);

int main()
{
	double d;
	double pi2d;
	double flr;
	int i;

	d = 1.48353;
	pi2d = 7.76671;
	flr = 4.9999999;
	i = 2;
	printf("double d = %7.4f\n", d);
	printf("int    i = %7i\n", i);
	printf("abs(i)   = %7i\n", abs(i));
	printf("cos(d)   = %7.4f\n", cos(d));
	printf("sin(d)   = %7.4f\n", sin(d));
	printf("tan(d)   = %7.4f\n", tan(d));
	printf("double d = %7.4f\n", pi2d);
	printf("cos(d)   = %7.4f\n", cos(pi2d));
	printf("sin(d)   = %7.4f\n", sin(pi2d));
	printf("tan(d)   = %7.4f\n", tan(pi2d));
	printf("(int)flr  = %7i\n", (int)flr);
	printf("floor(flr)= %7.4f\n", floor(flr));
}
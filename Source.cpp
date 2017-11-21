/***************************************************
* 
* CS301 Project
* Hanbo Ye
* 11/21/2017
* The program locates roots
*
***************************************************/
#include<iostream>
#include<math.h>
using namespace std;

const int nMax = 100;

double f (double x)
{
	double fx1;
	fx1 = (x * cos(x)) - (2 * pow(x, 2)) + (3 * x) - 1;
	// fx1 = pow(x,3) - (7 * pow(x,2)) + (14 * x) - 6;
	return (fx1);
}

void swap(double x, double y) {

	double temp;
	temp = x;
	x = y;
	y = temp;
}
void bisection(double a, double b) {

	double c;
	int n = nMax;

	while (c != 0 || --n != 0)
	{
		c = (a + b) / 2;

		if ( f(a) * f(c) < 0)
		{
			b = c;
		} else
		{
			a = c;
		}
	}
}

void secant(double x2, double x1) {

	double d;
	double fx1 = f(x1);
	double fx2 = f(x2);

	for (int i = 0; i < nMax; i++)
	{
		if (fabs(fx2) > fabs(fx1))
		{
			swap(x2, x1);
			swap(fx2, fx1);
		}
		d = (fx2 - fx1) / (x2 - x1);
		x1 = x2;
		fx1 = fx2;
		d = fx2 / d;
		x2 = x2 - d;
		fx2 = f(x2);
	}
}

void modifiedSecant(double x) {

	double delta = 0.01;
	double fx = f(x);
	double fy = f(x + delta * x);
	double d = (fy - fx) / (delta * x);

	for (int i = 0; i < nMax; i++)
	{

	}

}

int main()
{
	

	return 0;
}
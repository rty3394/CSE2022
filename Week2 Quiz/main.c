#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double randnum(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;

	return temp;
}

bool chkcir(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;


	if (f > 0.0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void main()
{
	FILE *of = fopen("quiz.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100000; i++)
	{
		double x = randnum(0.0, 3.0);
		double y = randnum(0.0, 3.0);

		if (chkcir(x, y) == true)
		{
			fprintf(of, "%f %f\n", x, y);
		}		
	}
	fclose(of);
}
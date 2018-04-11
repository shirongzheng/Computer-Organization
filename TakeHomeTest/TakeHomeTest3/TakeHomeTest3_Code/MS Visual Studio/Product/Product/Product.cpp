// Product.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int Product(int x[], int y[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += x[i] * (y[i]);
	return sum;
}

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "const.h"
#include "prototypes.h"
using namespace std;

void fill_array (double x[])
{
	int i;
		cout << "Enter #'s   ";
	for (i = 0; i < MAX_SIZE; i++)
	{
	cin >> x[i];
	}
}

void compute_average (double x[], double &average)
{
	int i;
	double sum = 0;
	for (i = 0; i < MAX_SIZE; i++)
		sum = sum + x[i];
	average = sum/MAX_SIZE;
}

double compute_stdev (double x[], double average, double n)
{
	int i;
	double temp = 0;
	double stdev = 0;

	for (i = 0; i < MAX_SIZE; i++)
		temp = temp + ((x[i] - average) * (x[i] - average));
	temp = temp/(n-1);
	stdev = sqrt (temp);
	return (stdev);

}

int main ()
{
	double x[MAX_SIZE];
	double stdev;
	double average;
	double n = MAX_SIZE;

	//get values
	fill_array(x);


	//compute average
	compute_average(x, average);


	//compute standard deviation
	stdev = compute_stdev (x, average, n);

	cout << "Standard deviation is:  " << stdev << endl;

	return (0);
}
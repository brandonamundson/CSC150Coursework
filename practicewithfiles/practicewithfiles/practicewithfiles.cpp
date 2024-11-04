#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const int MAX_COL = 5;

void fill_array(double a[6][MAX_COL], int &nrows, ifstream &fin)
{
	int i, j;
	for(i=0; i<6; i++)
	{
		for(j=0; j<5; j++)
		{
			fin >> a[i][j];
		}
	}
	nrows = 6;
}
double find_avg(double a[6][MAX_COL], int nrows)
{
	double sum = 0;
	int i, j;
	double avg;

	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 5; j++)
		{
			sum+=(a[i][j])/30;
		}
	}
	avg = sum / 30;

	return(avg);
}
double find_closest(double a[6][MAX_COL], int nrows, double avg)
{
	int i, j, k = 0;
	double num;
	double smallest_diff = 100;
	double diff;

	for(i = 0; i < 6; i++)
	{
		for(j = 0; j < 5; j++)
		{
			diff= abs(avg - a[i][k]);
			if(diff < smallest_diff)
			{
				smallest_diff = diff;
				num = a[i][j];
			}
		}
	}
	return(num);
}
int main(int argc, char *argv[])
{
	ifstream fin;
	ofstream fout;
	int nrows;
	double a[6][MAX_COL];
	double sum;
	double close;

	fin.open(argv[1]);

	if(!fin)
	{
		cout << "Your file could not be opened" << endl;
		return(9);
	}

	fill_array(a, nrows, fin);
	sum = find_avg(a, nrows);
	close = find_closest(a, nrows, sum);

	cout << "The average is: " << sum << endl;
	cout << "The closest is: " << close << endl;




	return (0);

}
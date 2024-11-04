/***********************************************************************
Program 1


Class CSC 150
Section 001
Instructor: Dr. Logar

Location: McLaury - Room 306

Dates: 9/19-10/10

Author: Brandon Amundson

This program finds the root of (x^3) + x - (0.5cos(x)) on the interval a <= x <= b
using Newtons Method
*************************************************************************/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	/******************************************************************************
	defining of variables
	******************************************************************************/
	double start;					//value of a
	double end;						//value of b
	double guess;
	double d_guess;					//value of derivative with input of guess
	double function;				//function we are finding root for
	double f;						//value of b in equation y = (m * x) + b 
	double tolerance;
	int iterations = 1;				//iterations of the program
	double iterations_in;			//iterations input
	double okay;					//value used to compare tolerance
	double actual = .3972462;		//actual value of root
	double f_a;						//value of a from input used for error checking
	double f_b;						//value of b from input used for error checking

	cout << fixed << setprecision (6);  //# of decimals shown

	cout << "Please input a and b   " << endl << "a  b ";
	cin >> start >> end;

	if ( start >= end )				//error check
	{
		cout << "B must be bigger than A" << endl;
		return (1);					//error # 1
	}

	guess = (start + end) / 2;

	cout << "Please enter the error tolerance: ";
	cin >> tolerance;
	cout << "Enter the maximum number of iterations for the search:  ";	
	cin>> iterations_in;

	if ( tolerance < 0 || iterations < 0)	//error check
	{
		cout << "Error and Tolerance must be positive" << endl;
		return (2);					//error # 2
	}

	f_a = guess + pow( guess, 3) - (.5 * cos (guess));
	f_b = guess + pow( guess, 3) - (.5 * cos (guess));

	if ( f_a * f_b >= 0)			//warning that root may not exist
	{
		cout << "No sign change, root may not exist" << endl;
		//attempt to find root within 10 iterations
		do
		{

		d_guess = 1 + (3 * pow( guess, 2)) + (.5 * sin (guess));

		function = guess + pow( guess, 3) - (.5 * cos (guess));

		f = function - (guess * d_guess);

		guess = -f/d_guess;
		
		okay = abs(guess - actual);

		cout << "n = " << iterations << "		x = " << guess << endl;
	
		iterations++;

		}
		while ( iterations <= 10);

	}
	
	else 
	{
/********************************************************************
computation of root
*********************************************************************/
	do
	{

	d_guess = 1 + (3 * pow( guess, 2)) + (.5 * sin (guess));

	function = guess + pow( guess, 3) - (.5 * cos (guess));

	f = function - (guess * d_guess);

	guess = -f/d_guess;
		
	okay = abs(guess - actual);

	cout << "n = " << iterations << "		x = " << guess << endl;

	iterations++;
	
	}
	while ( okay >= tolerance);

	}

	return (0);

}
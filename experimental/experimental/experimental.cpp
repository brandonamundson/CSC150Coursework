#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------
// This program coputes the number of times one number divides another evenly,
// and the remainder
//
//
// Author: Brandon Amundson
// Date: September 3, 2014
// Required for CSC 150
//-------------------------------------------------------------------------------

int main()
{
	int numerator;
	int denominator;
	int dividend;
	int remainder;

	cout<< "Enter the numerator:  ";
	cin>> numerator;
	cout<< "Enter the denominator:  ";
	cin>> denominator;

	dividend = numerator / denominator;
	remainder = numerator % denominator;

	cout<< denominator << " divides " << numerator << " " << dividend << " times "
		<< "with a remainder of " << remainder << endl; 
}
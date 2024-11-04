#include <iostream>
#include <cmath>
using namespace std;
//-----------------------------
//  Author: Dr. Logar
//  Date : September 24, 2014
//
//  This program finds the square
//  root of a number using division
//  and looping.
//  Algorithm:
//     Enter a number num
//     Guess the sqrt  x
//     Enter your tolerance
//     Calculate quotient = num / x
//     if quotient = x, you are done
//     else compute the new value of x = the average of x and quotient
//     loop until abs|quotient - x| < some tolerance
//-----------------------------------------


int main ()
    {
    double num;                                                   // the number we are taking the square root of
    double tolerance;                                             // required accuracy for a match
    double x;                                                     // the current guess at the sqrt
    double quotient;
    double diff;
    double sys_result;

    cout << "This program finds the square root of a number." << endl;
    cout << "Enter the number : ";
    cin >> num;

    
    cout << "Enter your tolerance for error (e.g. .001) : " ;
    cin >> tolerance;
    

    cout << "Enter your guess for the square root : " ;
    cin >> x;

	if (num > 0)
	{
	do
	{
    quotient = num / x;
    diff = abs (x - quotient);
	}
    while ( diff > tolerance );
        {
        x = (x + quotient) / 2.0;
        quotient = num / x;
        diff = abs (x - quotient);
        }                                                         // end while
	
    cout << "The square root of " << num << " is : " << x << endl;
    sys_result = sqrt(num);
    cout << "The system library gives : " << sys_result << endl; 
    }
	else
	{
		cout << "Enter in a positive non-zero number: " << endl;
		exit (0);
	}
}// end main

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double start;					//figure out how to put in # of iterations
	double end;
	double tolerance;
	double result;
	double guess;
	cout << "Enter Start  ";
	cin >> start;
	cout << "Enter end  ";
	cin >> end;
	cout << "Enter tolerance  ";
	cin >> tolerance;
	
	guess = (start + end)/2;		//add f(guess)

	while (abs(guess) > tolerance)		//change guess to f(guess)
	{
		//Newtons Method
		guess = guess; //subtract f(x) and f'(x)
	}
	//return guess
}

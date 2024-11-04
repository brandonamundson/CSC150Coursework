#include <iostream>
using namespace std;

int main ()
{
	int op;
	double a;
	double b;
	double result;

	cout << "Enter a value for a:   ";
	cin >> a;

	cout << "Enter a value for b:   ";
	cin >> b;

	cout << "Enter an operator:   " << "Enter 1 for Add "  << endl << "Enter 2 for Subtract" << endl << "Enter 3 for Multiply" << endl << "Enter 4 for Divide" << endl;

	cin >> op;

	switch (op)
	{
	case 1 : result = a + b;
		break;
	case 2 : result = a - b;
		break;
	case 3 : result = a * b;
		break;
	case 4 : result = a / b;
		break;
	default : cout << "Not a valid operator  " << endl;
	}
	if ( (op > 4)  ||  ( op < 1 ))

	cout << "The result is " << result << endl;
	
	return (0);
	}
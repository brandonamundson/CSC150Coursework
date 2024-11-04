#include <iostream>
using namespace std;



//---------------------------------------------------------------
// This Program computes n!--------------------------------------
// input n


int main ()
{
// declare variables
	int n; // print the first n factorials
	int i;
	long long result;
	int j;
	result = 1;
	
//check integer size
	//cout << "A short is " << sizeof (short int) << endl;
	//cout << "An integer is " << sizeof (int) << endl;
	//cout << "A long is " << sizeof (long) << endl;
	//cout << "A long long is " << sizeof (long long) << endl;
	//cout << "A double is " << sizeof (double) << endl;
	//cout << "A long double is " << sizeof (long double) << endl;
// input
	cout << "Please input n: ";
	cin >> n;

// processing section
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i ; j++)
		{
			result = result * j;
		}
		cout << "The result of " << i << " is " << result << endl;
	}

// output section
	//cout << "The factorial of " << n << " is " << result << endl << endl;
}
#include <iostream>
using namespace std;


int main ()
{
	double c;
	double f;
	

	cout << "Enter the temperature in Celcius:  ";
	cin >> c;
	
	f = 9.0/5.0 * c + 32;

	cout << "The temperature in Farenheit is:  ";
	cout << f;
	cout << endl;

	return (0);
}
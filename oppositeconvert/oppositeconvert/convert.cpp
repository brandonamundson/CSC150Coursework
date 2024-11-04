#include <iostream>
using namespace std;


int main ()
{
	double c;
	double f;
	

	cout << "Enter the temperature in Farenheit:  ";
	cin >> f;
	
	c = (f - 32)* (5.0/9.0);

	cout << "The temperature in Celcius is:  ";
	cout << c;
	cout << endl;

	return (0);
}
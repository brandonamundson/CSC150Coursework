#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x;
	double y;
	double pi;

	pi=3.14159;
	cout << "Please enter radius: ";
	cin >> x;

	y=((4/3)*pi*(x*x*x));
	cout << y << endl;
	return (0);
}
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a;
	double b;
	double c;
	double temp;                          //(b*b)-(4*a*c)
	double temp_sqrt;                     //sqrt (z)... pow(z,1.0/2.0)
	double x1;                          
	double x2;                          



	cout << "Please input a: ";
	cin >> a;
	cout << "Please input b: ";
	cin >> b;
	cout << "Please input c: ";
	cin >> c;

	temp= (b * b) - (4 * a * c);
	temp_sqrt= pow(temp,1.0/2.0);                  //fix for when z is negative
	x1 = - b + temp_sqrt;
	x2 = - b - temp_sqrt;
	x1 = x1 / (2*a);
	x2 = x2 / (2*a);

	cout << "The first root is ";
	cout << x1 << endl;
	cout << " The second root is :";
	cout << x2 << endl;

	return (0);
}
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double r;
	double v;
	double angle;
	double pi;
	double fin;


	fin = 0;
	v = 0;
	r = 0;

	pi = 3.14159265358979323846;

	cout << "Please enter speed (in feet per second): ";
	cin >> v;
	cout << "Please enter angle (in degrees): ";
	cin >> angle;

	fin = (((2 * pi) * angle) / 360);

	r = (((1/32) * (v * v)) * ( sin (2*fin) ));

	cout << "You hit the ball " << r << " feet" << endl;

	return (0);
}
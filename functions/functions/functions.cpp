#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
double circle (double radius);
double circle_area (double radius);

int main ()
{
	double area;
	double circumference;
	int choice;
	double radius;

	cout << "This program calculates circumference and area" << endl;
	cout << "Menu" << endl << "1. Circumference" << endl << "2. Area" << endl;
	cout << "What would you like to calculate? Please enter your choice.  ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Please enter radius  ";
		cin >> radius;
		circumference = circle (radius);
		cout << circumference << endl;
		break;
	case 2:
		cout << "Please enter radius  ";
		cin >> radius;
		area = circle_area (radius);
		cout << area << endl;
		break;
	default:
		cout << "Please enter only one or two" << endl;
		break;
	}
}

double circle (double radius)
{
	double circumference;

	circumference = 2 * M_PI * radius;
	return (circumference);
}

double circle_area (double radius)
{
	double area;
	
	area = M_PI * radius * radius;

	return (area);
}
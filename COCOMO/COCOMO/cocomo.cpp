#include <iostream>
#include<cmath>
using namespace std;

int main ()
{
	double PM;
	double TDEV;
	double LOC;
	int choice;
	int count = 0;

	cout << "Welcome to the COCOMO estimator" << endl;
	
	do
	{
		cout << "Please enter Lines of code expected (in thousands)   ";
		cin  >> LOC;
		if (LOC <= 0)
		{
			count++;
			if (count > 3)
			{
			cout << "Too many retries" << endl;
			return (-1);
			}

			else cout << "Please enter a number greater than zero" << endl << endl;
		}
	}
	while (LOC <=0 && count <=3);

	do
	{
	cout << "Enter your project type" << endl;
	cout << "1. Simple" << endl << "2. Complex" << endl << "3. Embedded" << endl;
	cout << "> ";
	cin >> choice;

	if (choice > 3 || choice < 1)
		cout << "Enter only 1, 2, or 3" << endl;
	}

	while (choice > 3 || choice < 1);

	switch (choice)
	{
	case 1:
		PM = 2.4 * pow (LOC, 1.05);
		TDEV = 2.5 * pow (PM, .38);
		break;
	case 2:
		PM = 3.0 * pow (LOC, 1.12);
		TDEV = 2.5 * pow (PM, .35);
		break;
	case 3:
		PM = 3.6 * pow (LOC, 1.2);
		TDEV = 2.5 * pow (PM, .32);
		break;
	default:
		cout << "Error";
		break;
	}
	cout << "PM = " << PM << endl << "TDEV = " << TDEV << endl;

	return (0);

}
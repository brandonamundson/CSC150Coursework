#include <iostream>
using namespace std;

int main()
{
	char response;


	cout << "Do you like CSC 150? (enter y or n) ";
	cin >> response;

	if (response == 'y' || response == 'Y')
		cout << "Good!  You are smart!" << endl;
	else if (response == 'n' || response == 'N')
		cout << "WHAT!  Why not??" << endl;
	else
		cout << "Stop fooling around and enter Y or N!" << endl;
	cout << "Thanks for taking my survey" << endl;
	return (0);
}
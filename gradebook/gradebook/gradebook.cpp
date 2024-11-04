#include <iostream>
using namespace std;

int main ()
{
	char response;

	cout << "What grade did you get? (A, B, C, D, F) ";
	cin >> response;

	if (response == 'A' || response == 'a')
		cout << "Good! You are smart!" << endl;
	else if (response == 'B' || response == 'b')
		cout << "Not Bad..." << endl;
	else if (response == 'C' || response == 'c')
		cout << "You can do better!" << endl;
	else if (response == 'D' || response == 'd')
		cout << "WHAT IS WRONG WITH YOU!!!" << endl;
	else if (response == 'F' || response == 'f')
		cout << "Hope you are rich enough to take this class again and again and again and again and again!" << endl;
	else
		cout << "Stop fooling around and enter a grade" << endl;
	return (0);
}

#include <cstring>
#include <iostream>
using namespace std;

int main ()
{
	char name1[20];
	char name2[20] = {"Tommy"};
	char name3[20] = {'L', 'o', 'u'/*'\0'*/};
	int len;
	int i;

	cout << "Enter the first name  ";
	cin >> name1;

	len = strlen(name1);
	cout << "The length of name 1 is  " << len << endl;

	len = strlen(name2);
	cout << "The length of name 2 is  " << len << endl;

	cout << "Enter name 3";
	cin >> name3[i];

	//len = strlen(name3);
	//cout << "The length of name 3 is  " << len << endl;
	strcpy(name3, name1);


	cout << "The first name is " << name1 << endl;
	cout << "The second name is " << name2 << endl;
	cout << "The third name is  " << name3 << endl;

	if (strcmp(name1, name3) ==0)
		cout << "Name 1 and Name 2 are the same" << endl;
	else if (strcmp(name1, name2) < 0)
		cout << "name 1 is before name 2 in phone book" << endl;
	else
		cout << "Name 3 is not equal to name 1" << endl;


	return (0);
}
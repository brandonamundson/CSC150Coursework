#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <cstring>
using namespace std;

//prototype here
void combine (char &z,char x, char y);

int main()
{
	char str1[25] = "";
	char str2[25] = "";
	char str3[40] = "";  //note this is not twice the size of str1 or str2
	int i;

	cout << "Enter your first phrase (24 or fewer characters: ";
	for (i = 0; i < 25; i++)
		cin >> str1[i];

	cout << "Enter your second phrase (24 or fewer characters: ";
	for (i = 0; i < 25; i++)
		cin >> str2[i];

	combine( str3,/*40,*/ str1, str2 ); //note order of arguments

	cout << endl << endl;

	cout << "String1: " << str1 << endl;
	cout << "String2: " << str2 << endl;
	cout << "Combined string: " << endl;
	
	return 0;
}

//function definition here
	
void combine (char &z, char x, char y)
{

}
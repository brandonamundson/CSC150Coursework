#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main ()
{
	ifstream fin;
	ofstream fout;
	int i;
	char infilename[100];
	char outfilename[100];
	int temp;
	int num;

	cout << "Enter the name of the output file";
	cin >> infilename;
	fin.open(infilename);
	

	if(!fin)
	{
		cout << "Cannot open the input file.  Exiting the program" << endl;
		exit (1);
	}
	i = 0;
	while (infilename[i] != '.')
	{
		outfilename[i] = infilename[i];
		i++;
	}
	outfilename[i] = '\0';
	strcat(outfilename, ".out");
	fout.open(outfilename);
	
	if(!fout)
	{
		cout << "Cannot open the output file.  Exiting the program.  " << endl;
		exit (1);
	}

	num = 0;
	while (fin >> temp)	//do not use fin.eof
	//fin >> num;
	//for (i = 0; i < num; i++)
	{
		fin >> temp;
		temp = temp + 10;
		fout << temp << endl;
		num++;
	}
	cout << "Read " << num << " numbers" <<endl;
	fin.close ();
	fout.close ();
}
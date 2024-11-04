#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//just declared a new type, aka int, float, double, etc
struct student
{
	char name[80];
	double gpa;
	int age;
};

int main()
{
	ifstream fin;
	ofstream fout;
	student s[10];
	double max = 0;
	int index = 0;
	int i = 0;
	int count;
	fin.open("studentreqs.in");
	if (!fin)
	{
		cout << "Unable to open file";
		return (199);
	}
	
	while (fin >> s[count].name)
	{
		fin >> s[count].gpa;
		fin >> s[count].age;
		count++;
	}

	for(i = 0; i < count; i++)
	{
		if(s[i].gpa >= 3.0)
		{
			cout << s[i].name << " " << s[i].gpa << endl;
		}
	}
	//cout << "The largest gpa is " << max << " and it belongs to " << s[index].name << "." << endl;

}
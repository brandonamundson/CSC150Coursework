#include <iostream>
using namespace std;

int fill_array( int x);
//int find_largest(int x);

int main()
{
//int   j;
int   index = 0;
int   my_array[10];
int   num_elements = 0;

num_elements = fill_array(my_array[10]);
cout << my_array[index];

//index = find_largest(my_array[10]);
//cout << "The largest is:  " << my_array[index] << endl;

return 0;
}

//fills array till full or user enters ctrl-z, whichever comes
//first
int fill_array(int my_array[ ])
{
	int i;
		cout << "Enter #'s   ";
	for (i = 0; i < 10; i++)
	{
	cin >> my_array[i];
	}
	return (my_array[i]);
}

//int find_largest(                                        )
//{
//
//
//
//
//
//
//
//
//
//
//
//}  // end of function find_largest
//

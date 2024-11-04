#include <iostream>
using namespace std;
//-----------------------------------------
//  This program finds the maximum of every group
//   of 15 numbers.
//  If there aren't a full 15 in a group,
//  it is ignored.
//----------------------------------------------

//-----------------------
// function prototypes
//-----------------------
void get_max_of_15(const int array[], int &max);
bool get_15_values(int array[]);

//------------------------------------------
// Returns the largest number
// in the group.
//  There should be 15 in the array or
//  this function is not called
//   Note: Arrays are automatically passed by reference
//     use const to protect values in the array
//     if you aren't planning to change them
//   Note:  max is passed by reference since it
//   will be set in the function.
//   This is a non-valued function.
//-----------------------------------------
void get_max_of_15(const int array[], int &max)
    {
    
    max = array[0];
    for (int i = 1; i < 15; i++)
        if (array[i] > max)
            max = array[i];
     }


//----------------------------------------
//  Gets 15 values unless a negative
//  is entered.  If less than 15 numbers
//  are entered, the functino returns false.
//  If a full set of 15 is entered, it returns true.
//   Note: valued function.  Don't use const here
//   or you can't fill in the array 
//-----------------------------------------------------
bool get_15_values(int array[])
    {
    bool flag = true;  // need a local variable to return.  Type
                       // must match that of the valued function (bool)
    int i = 0;
    int temp;

    cout<< "Enter value " << i+1 << " :";
    cin >> temp;
    array[0] = temp;
    i++;

    while (temp >= 0 && i < 15)
        {
        cout<< "Enter value " << i+1 << " :";
        cin >> temp;
        array[i] = temp;
        i++;
        }

    if (i < 15)
        flag = false;

    return(flag);   // return the local variable
    }

//-------------------------------
//  Get 15 numbers.  If 15 entered,
//  find and store the larget and ignore
//  the rest.
//  A negative ends the loop.
//---------------------------------
int main()

    {
    int max_array[100];  // array to hold largest value in each group
    int max;             // largest of one group - returned to main
    int array[15];       // a single group
    int count = 0;       // number of groups of 15 entered
    bool flag = true;    // true signals 15 elements were entered

    flag = get_15_values(array);
    while (flag == true)
        {
        get_max_of_15(array, max);
        max_array[count] = max;
        count++;
        cout << "----------" << endl;
        flag = get_15_values(array);
        }

    if (count != 0)
       cout << "The largest values in each set of 15 are: ";

    for (int i = 0; i < count; i++)
        {
        cout << max_array[i] << " " ;
        }
    cout << endl;
    }
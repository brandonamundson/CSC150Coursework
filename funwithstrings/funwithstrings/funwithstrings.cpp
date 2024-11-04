//----------------------------------------
// This program demonstrates the use of the 
// major string functions, shows how to pass
// a string to an array, shows how to use
// an array of strings and how to pass that
// array of strings to a function.
//
// The main string functsion are :
//   strlen = string length
//   strcpy(str1, str2) = copy str2 into str1
//   strcmp(str1, str2) = computes str1 - str2
//   strcat (str1, str2) = appends str2 to the end of str1
//   strupr(str1) = converts to all upper case
//   strlwr(str1)= converts to all lower case
//   strrev(str1)= reverses str1 
//----------------------------------------  

#include <iostream>
#include <cstring>
using namespace std;

//----------------------------------------------------
//  This function fills the array of names
//  Note how the array is passed - same as
//  2D arrays previously. Number of columns required.
//----------------------------------------------------

void fill_section(char students[][80], int size)
  {
  int i;

  cout << "Enter first name last name" << endl;
  cin.ignore();
  for (i = 0; i < size; i++)
   {
   cout << "Enter name : " ;
   cin.getline(students[i], 80);
   }
  }

//----------------------------------------------------
//  This will print the roster as originally entered.
//----------------------------------------------------
void print_roster(char section_name[], char students[][80], int size)
  {
  int i;

  cout << endl << endl;
  cout << "Roster for " << section_name << endl;
  for (i = 0; i < size; i++)
   {
   cout << students[i] << endl;
   }
  }

//----------------------------------------------------
//  This will print the roster last, first
//----------------------------------------------------
void print_last_first(char section_name[], char students[][80], 
                      int size, char last_first[][80])
  {
  int i, j, k, n;
  char first[80];
  char last[80];

  cout << endl << endl;
  cout << "Roster for " << section_name << endl;
  for (i = 0; i < size; i++)
   {
   // step through the name looking for blank
   j = 0;
   while (students[i][j] != ' ' && j < strlen(students[i]))
     j++;
   // copy the first name
   strncpy(first, students[i],j);
   first[j] = '\0';
   // loop through and get the last name
   // start from letter after the comma
   n = 0;
   for ( k = j+1; k < strlen(students[i]); k++)
      {
      last[n] = students[i][k];
      n++;
      } 
   // don't foret to terminate the string
   last[n] = '\0';
   cout << last << ", " << first << endl;
   strcat(last, ", ");
   strcat(last,first);
   strcpy(last_first[i], last);       
   } // end for
  }

//-------------------------------------------
//  This function finds the student whose last 
//  name is first in an alphabetical listing
//-------------------------------------------
void find_first(char last_first[][80], int size)
  {
  char temp[80];
  int i;
  
  strcpy(temp, last_first[0]);
  for (i = 1; i < size; i++)
    {
    if (strcmp(temp, last_first[i]) > 0)
      strcpy(temp, last_first[i]);
    }
  cout << endl << endl;
  cout << "The first name on the list should be " << temp << endl;
  }

//-------------------------------------------
// Main program
//  calls : print_roster
//          print_last_first
//          find_first
//-------------------------------------------
int main()
  {
  char section_name[80];
  char students[10][80];
  char last_first[10][80];
  int size;

  cout << "Enter the name of the section : ";
  cin >> section_name;
  strupr(section_name);

  cout << "Enter the number of students in " << section_name << " : ";
  cin >> size;

  fill_section(students, size);
  print_roster (section_name, students, size);

  // print names last, first
  // does not change the original array
  print_last_first (section_name, students, size, last_first);
  print_roster (section_name, students, size);
  print_roster (section_name, last_first, size);

  // find person who has first name alphabetically
  find_first(last_first, size);
  
  return (0);
  }
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void fill_array(char words[ ][80],ifstream &infile, int &n);
void bubble_sort(char words[ ][80], int n);

void fill_array(char words[ ][80],ifstream &infile, int &n)
    {
    int i;

    i = 0;
    while(infile >> words[i])
        i++;
    n = i;
    }


void bubble_sort(char words[ ][80], int n)
    {
    int i, j;
	char temp;
    bool swap_made = true;

    i = 0;
    while ( swap_made == true)
      {
      swap_made = false;
      for (j = 0; j < n-1-i; j++)
        {
        if ( strcmp(words[j], words[j+1]) > 0 )
          {
          strcpy(temp, words[j]);
          strcpy(words[j], words[j+1]);
          strcpy(words[i+1], temp);
          swap_made = true;
          }
        }
      i++;
      }
    }


int main()
    {
    char words[100][80];
    int i, n;
    bool swap_made = true;
    ifstream infile;
    ofstream outfile;

    // read in the values from a file
    infile.open("bubble_in.txt");
    if (!infile)
        {
        cout << "Open failed" << endl;
        exit(1);
        }

    // call fill_array to get the values into the array
    fill_array(words, infile, n);

    for (i = 0; i < n; i++)
        cout << words[i] << "  ";
    cout << endl;

    // call bubble sort
    bubble_sort(words, n);
       
    for (i = 0; i < n; i++)
        cout << words[i] << "  ";
    cout << endl;

    outfile.open("bubble_out.txt");
    for (i = 0; i < n; i++)
        outfile << words[i] << "  " << endl;

    outfile.close();
    infile.close();
    }

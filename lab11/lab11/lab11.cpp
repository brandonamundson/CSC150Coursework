/*--------------------------------------------------------------------
  Program: lab11.cpp
  Author: Brandon Amundson
  Course: CSC 150 - 
  Instructor: Stephanie A.
  Date: 11/20/2014
  Description: This program reads in the standard size and weight data
    for reinforcing steel (rebar) used in construction and the requirements
    for a particular project. The rebar specifications and the project
    data are stored to 2D arrays, then the program displays the required
    rebar sizes, diameters, lengths, and weights, with a summary line that
    displays total length and total weight.
    
---------------------------------------------------------------------
  Includes
---------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//-------------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------------

double calc_weight(double feet, double rebar[][2], int index);
bool read_data(char fname[], int sizes[], double rebar[][2]);

/********************************************************************
   Function:      main
   Description:   Program entry/exit point, prompts for inputs, 
                  performs calculations, displays results
   Parameters:    none
   Returns:       0
   Called by:     none
   Calls:         calc_weight()  
*********************************************************************/
int main( )
{
    // Variable declaration
    int sizes[12]/* = { 0 }*/;
    double rebar[12][2]/* = { 0 }*/;
    double reqs[10][2]/* = { 0 }*/;
    int num_reqs = 0;
    double weight = 0;
    double total_weight = 0;
    double total_length = 0;
    int needed_size = 0;
    int rebar_index = 0;
	bool success = false;
	char fname[12] = {"rebar.txt"};
    int i;

    ifstream fin;
	ofstream fout;

	/*call function to read rebar information file*/
    success = read_data(fname, sizes, rebar);
	if( success == false )
	{
		cout << "Error opening rebar file. Exiting." <<endl;
		return -1;
	}

	/*open requirement file, check for success */
    fin.open("requirements.txt");
    if(!fin)
    {
        cout << "Error opening requirements file. Exiting." <<endl;
        return(-1);
    }

    i = 0;

	/* read the requirements file, store to 2D array */
    while(!fin.eof())
    {
		for ( i = 0; i < 10; i++)
			for (int j = 0; j < 2; j++)
				fin >> reqs[i][j];
    }

    fin.close();

    num_reqs = i;//save the number of items in requirements file

	/*when program runs correctly on screen, add code here to
	 open output file, check it. Make changes to output statements
	 so that all output from here on goes to file, not screen */

    cout << setprecision(3);

    cout << left << setw(12) << "SIZE" << setw(12) << "DIAMETER" << setw(10)
         << "LENGTH" << setw(10) << "WEIGHT" << endl;

    for( i = 0; i < num_reqs; i++ )
    {
        needed_size = (int)reqs[i][0];
		rebar_index = 0;
	    while( needed_size != sizes[rebar_index] )
			rebar_index++;

		/*call function to calculate weight, given feet, rebar info, index */
		weight = calc_weight(reqs[10][1], rebar, rebar_index);
        
		total_weight += weight;
        total_length += reqs[i][1];
 
        cout << setw(10) << left <<  setprecision(0) << noshowpoint << reqs[i][0] 
             << right << setw(10) << showpoint
             << setprecision(3) << rebar[rebar_index][1] << setprecision(1)
             << setw(10) << reqs[i][1] << setw(10) << weight << endl;
    }

    cout << left << setw(20) << "Total" << right << setw(10) 
         << total_length << setw(10) << total_weight << endl;


   return (0);
}

/*write your two functions here */
double calc_weight(double feet, double rebar[][2], int index)
{
	double weight = 0;

	weight = feet * rebar[index][0];

	return (weight);
}
bool read_data(char fname[], int sizes[], double rebar[][2])
{
	ifstream fin;
	int i = 0;
	int j = 0;

	fin.open(fname);
    if(!fin)
    {
        //cout << "Error opening rebar file. Exiting." <<endl;
        return(false);
    }

	while(i <= 36)
	{
		fin >> sizes[j];
		i++;
		fin >> rebar[j][0];
		i++;
		fin >> rebar[j][1];
		i++;
		j++;
	}
	//while(fin.eof())
	//{
	//for(i = 0; i < 12; i++)
	//{
	//	fin >> sizes[i];
	//	for ( j = 0; j < 2; j++)
	//	{
	//		rebar[i][j];
	//	}
	//}
	//}
	fin.close();
	return (true);
}
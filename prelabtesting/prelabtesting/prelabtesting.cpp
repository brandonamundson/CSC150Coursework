//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//using namespace std;
//
//const int PAGES = 5;
//const int ROWS = 6;
//const int COLUMNS = 7;
//
//void find_max (int data[PAGES][ROWS][COLUMNS]);
//void fill_array( int d[ ][ROWS][COLUMNS], int pages); 
//
//
//int main()
//{
//    int data[PAGES][ROWS][COLUMNS] = { 0 } ;
//    int page_ind = 0;
//    int row_ind = 0;
//    int col_ind = 0;
//
//    fill_array( data, PAGES );
//
//	find_max(data);  //find max in just page 0
//    cout << "The maximum value in the first page is: " 
//         << data[page_ind][row_ind][col_ind] << endl;
//
//    find_max(data); //find max in whole array
//    cout << "The maximum value in the entire array is: " 
//         << data[page_ind][row_ind][col_ind] << endl;
//
//    cout << endl;
//    return 0;
//}
//
//void fill_array( int d[PAGES][ROWS][COLUMNS], int pages )
//{
//    srand( unsigned ( time( NULL ) ) );
//
//    int pg, rw, cl;
//
//    for( pg = 0; pg < pages; pg++ )
//        for( rw = 0; rw < ROWS; rw++ )
//            for( cl = 0; cl < COLUMNS; cl++ )
//                d[pg][rw][cl] = rand( ) % 1000;
//
//}
//
//
////your function definition here
//void find_max(int d[PAGES][ROWS][COLUMNS]/*, int max*/)
//{
//	int i;
//	int j;
//	int k;
//	int max = 0;
//
//	for(i = 0;i < PAGES; i++)
//	{
//		for( j = 0; j < ROWS; j++)
//		{
//			for( k = 0; k < COLUMNS; k++)
//			{
//				if( i == 0)
//				{
//					if (d[i][j][k] > max)
//					{
//					max = d[i][j][k];
//					break;
//					}
//				}
//				else
//					if(d[i][j][k] > max)
//					{
//						max = d[i][j][k];
//					}
//			}
//		}
//	}
//}
//



// This program reads in the names of salesmen and their sales figures 
// (in thousands) on the four quarters of a year. The program then
// computes the total sales for each salesmen and prints the name of a
// salesmen and his or her total sales. The program terminates when 
// the user types Crtl-Z.  The data is read as: John 20 80 95 45

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	char name[40];	// Store a salesperson's name
	int sales;		// Store a salesperson's quarterly sales
	int total = 0;	// Accumulate sales
	
	// Read in first name 
	fin.open("sales.txt");

	if (!fin)
	{
		cout << "Could not open file" << endl;
		return(0);
	}
	// Read in each name and sales
	while( fin >> name )
	{
		total = 0;
		for (int i=0; i < 4; i++)
		{
			fin >> sales;
			total += sales;
		}

		fout << name << " has total sales: " << total << endl;
		fout << "Enter name and the four quarters sales: ";
		
	}

	return 0;
}

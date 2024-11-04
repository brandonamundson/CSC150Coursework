#include <iostream>
using namespace std;


void print_array(int a[][5], int nrows, int ncols);
int find_max_in_row (int a[5], int ncols);
void find_max_in_col(int a[][5], int nrows, int ncols);


void print_array(int a[][5], int nrows, int ncols)
    {
    int i, j;

    for (i = 0; i < nrows; i++)
        {
        for (j = 0; j < ncols; j++)
            cout << a[i][j] << "  ";
        cout << endl;   // note this is outside the j loop and inside the i loop
        }
    }

//  Only one row of hte matrix has been passed in
//  Find the max in that row and return it
int find_max_in_row (int a[5], int ncols)
    {
    int i;
    int max;

    max = a[0];
    for (i = 0; i < ncols; i++)
        {
        if (a[i]> max)
            max = a[i];
        }

    return(max);
    }

//----------------------------------------------------------------------------
//  I passed in the entire array because it is not easy to pass one column
//   Why?  Because C++ stores matrix values by row
//
//  This time I store the max of a col as I find it rather than returning it.
//  This is more efficient since I want to find the max for every column.
//  The find_max_in_row function is written the other way for comparison.
//  Process the whole array in the function if you are doing an operation for 
//  every row or column (like this function).  If you may only want to do an
//  operation for a particular row, do it the way find_max_in_row is written
//-----------------------------------------------------------------------------
void find_max_in_col(int a[][5], int nrows, int ncols)
    {
    int i, j;
    int max;

    // Note that to process a column, just switch the order of
    // the row and col loops.  Usually we have for (i = ...) for rows
    // with for (j = ...) for columns nested inside (look at the print routine for example)
    // Now the loop that processes the columns for (j =..) is outside the row loop  for (i = ...)
    
    for (j = 0; j < ncols; j++)
        {
        // note where this is set.  This is critical!  Don't initialize once at the
        // top.  Initialize max for every column you process.
        max = a[j][0];
        for (i = 0; i < nrows; i++)
            {
            if (a[i][j] > max)
                max = a[i][j];
            }
        // data is in rows 0, 1, 2.  The max is in row 3.
        a[3][j] = max;
       }
    }


int main()
    {
    // note: I am leaving an extra row and extra col for the max values
    // I will compute in the program.  The data occupies 3 rows and 4 columns
    // When I am finished, there will be data in all 4 rows and all 5 cols
    int a[4][5] = {{1, 2, 3, 4}, {7, 6, 5, 4}, {4, 9, 2, 8}};
    int max;
    int i;

    // currently I am only using the 3 rows and 4 cols
    cout << "Printing original array values: " << endl;
    print_array (a, 3, 4);
    cout << endl;

    // loop through every row and find the max in that row
    // max contains the largest value in the row
    // note that I send in a row, not the whole array
    // Also note that I send in the number of columns in the row
    for (i = 0; i < 3; i++)
        {
         max = find_max_in_row (a[i], 4);
         a[i][4] = max;
        }
    // now find the max in each column.  This time, note that I am
    // passing the entire array, not just a row or column.
    //  Why?  To show the difference and because you can't easily
    //  pass one column.  You have to copy it into a 1D array first.
    // Note that I pass the array name - a - not a[i] like last time
    //  Also note that there are now *5* columns of data to look at because
    //  we added the max in a row.  The last row, last col will be the overall max in the array
    find_max_in_col (a, 3, 5);

    // now I need to print 4 rows and 5 cols
    // because I have filled them in
    cout << "Printing array with max values for each row (in last column) and each column (in last row):" << endl;
    print_array(a, 4, 5);
    cout << endl;

    }
//  CSC 150  Lab 10  USPS address formatter
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void split_addr(char address[], char temp_addr[5][50]);
void display_addr(char temp_addr[5][50]);
void abbrev_street(char street [50]);

/* *****   DO NOT MAKE ANY CHANGES TO main( )   *****  */
int main()
{
	char addresses[5][100] = {
		"Ed Begely,123 Main Street,Riley,CO,59999",
		"Sally Struthers,2345 East Moon Lane,Hollywierd,CA,92111",
		"Billy Gates,1 Rich Place,Medina,WA,98000",
		"Big Bad Wolf,99 Forest Drive,Big Redwoods,OR,97654",
		"Joe Piggy,43 Straw Circle,Big Redwoods,OR,97800" };
    
	char temp_addr[5][50] = { "" };
	int i;

	for( i = 0; i < 5; i++ )
	{
		split_addr( addresses[i], temp_addr );
		display_addr(temp_addr);
		cout << endl;
	}

    return 0;
}


/* *****   complete the following function, write the other two   *****  */

//converts a street address to have the correct abbreviation
void abbrev_street(char street[50])
{
	char words[12][10] = { "BOULEVARD", "CENTER", "CIRCLE", "COURT",  
							"DRIVE", "LANE", "PLACE", "ROAD", "SQUARE",
							"STREET", "TERRACE", "TRAIL" };
	char abbrevs[12][6] = { "BLVD", "CTR", "CIR", "CT", "DR", "LN",
							"PL", "RD", "SQ", "ST", "TER", "TRL" };
	int i;
	char temp[10] = "";
	char temp_st[50] = "";	

	strrev(street);
	for (i = 0; i < 12; i++)
	{
		strcpy(temp, words[i]);
		strrev(temp);
		if (strncmp(street, temp, strlen(temp)) == 0)
		{
			strrev(street);
			strncat(temp_st, street, (strlen(street) - strlen(words[i])));
			strcat(temp_st, abbrevs[i]);
			strcpy(street, temp_st);
		}

	}
	strcmp (words[10], street);
}

void split_addr(char address[], char temp_addr[5][50])
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (j = 0; j < 5; j++)
	{
		while (address[i] != ',' && address[i] != '\0')
		{
			temp_addr[j][k] = address[i];
			k++;
			i++;
		}
		temp_addr[j][k] = '\0';
		k = 0;
		i++;
	}
}

void display_addr(char temp_addr[5][50])
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
	strupr(temp_addr[i]);
	if (i == 1)
	{
		abbrev_street(temp_addr[i]);
	}

	cout <<temp_addr[i] << endl;
	}
	for (i = 2; i < 5; i++)
	{
		strupr(temp_addr[i]);
		cout << temp_addr[i] << " ";
	}

	cout << endl;
}
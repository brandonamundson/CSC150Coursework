/***************************************************************************//**
 * @file 
 * @brief Demonstrates the use of arrays and passing through functions
 *
 * @mainpage Program 3 - Simple Cipher
 *
 * @section course_section Course Information
 *
 * @authors Brandon Amundson
 *
 * @date December 08, 2014
 *
 * @par Instructor:
 *         Dr. Logar
 *
 * @par Course:
 *         CSC 150 - Section 1 - 10:00 am
 *
 * @par Location:
 *         McLaury - Room 306
 *
 * @section program_section Program Information
 *
 * @details This program will encrypt or decrypt a file using
 * a basic encryption method
 *
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> prog3.exe
   d:\> c:\bin\prog3.exe
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug-will not decrypt, outputs only a
 * @bug-will not accept -e or -d no matter how i code it only accepts e or d with current coding
 *
 * @todo fix bugs 
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  ---------------------------------------------------------------
   Nov 14, 2014  Started writing the program
   Nov 25, 2014  verified the functions, and started on writing main
   Dec 03, 2014  added doxygen coding and attempted to correct the readtext function
   Dec 08, 2014  worked on completing, encountered bugs, attempted to debug
   
   @endverbatim
 *
 ******************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include "header.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that takes input file and reads contents of txt file,
 * storing the contents into a 2d text array, and keeping the # of lines in nrow
 *
 * @param[in] text[][MAXSIZE] - Text read from file.
 * @param[in] nrow - number of rows in text.
 * @param[in] reader - input file stream
 * 
 * @returns nothing 
 *
 *
 ******************************************************************************/

void readText(char text[][MAXSIZE],int &nrow, ifstream &reader)			//when passing file must always pass by reference
{
	char temp[MAXSIZE];
	nrow = 0;

	while(reader.getline(temp,MAXSIZE))
	{
		strcpy(text[nrow], temp);
		nrow++;
	}
}


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that takes input file handle and read the contents of the number file,
 * store them into number 1D array, and keep the count of numbers in size.
 *
 * @param[in] number[] - number read in from file.
 * @param[in] size - size of number array
 * @param[in] reader - input file stream
 * 
 * @returns nothing
 *
 *
 ******************************************************************************/

void readNumber(int number[], int &size, ifstream &reader)
{
	size = 0;
	while(reader>>number[size])
	{
		size++;
	}
}


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that takes the key 2D array, the number of row of 
 * the key array to fill the occurence 2D array with letter sequence numbers
 * and fill the letterCount 1D array with the occurence counts of the 27
 * encryptable characters.
 *
 * @param[in] key[][MAXSIZE] - keyfile to be read.
 * @param[in] nrow - number of rows in key.
 * @param[in] letterCount[] - # of letters in key
 * @param[in] occurence - # of times a specific character occurs
 * 
 * @returns True- when all characters are included in keyfile
 * @returns False- when all characters are not included in keyfile
 *
 *
 ******************************************************************************/

bool findLetter(char key[][MAXSIZE], int nrow, int letterCount[], int occurence[][MAXSIZE])
{
	int i, j = 0;
	int index;
	int idc = 1;
	bool ok = true;

	for( i = 0; i < nrow; i++)
	{
		//int n = strlen(key[i]);
		for (j = 0; key[i][j] && key[i][j] != '\0'; j++)
		{

			key[i][j] = tolower(key[i][j]);
			if ( key[i][j] == ' ')
			{
				index = 27;
				occurence[index][letterCount[index]] = idc;
				letterCount[index]++;
			}
			else
			{
				index = key[i][j] - 'a' + 1;
				occurence[index][letterCount[index]] = idc;
				letterCount[index]++;
			}
			idc++;
		}
	}
	for(i = 1; i < 28; i++)
	{
		if(!(letterCount[i]))
		{
		ok = false;
		return(ok);
		}
	}
	return(ok);
}


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that takes the plainText, the number of row of the plainText 2D array,
 * the letterCount, the sequence number of letter occurences and the output file handle
 * to encrypt the plaintext and print the ciphertext(numbers) to the output file.
 *
 * @param[in] plaintext[][MAXSIZE] - unknown.
 * @param[in] nrow - number of rows in key.
 * @param[in] letterCount[] - number of letters in file
 * @param[in] occurence - # of times a specific character occurs
 * @param[in] writer - output file stream
 * 
 * @returns nothing
 *
 *
 ******************************************************************************/

void encrypt(char plainText[][MAXSIZE], int nrow, int letterCount[], int occurence[][MAXSIZE], ofstream &writer)
{
	int i, j = 0;
	int index;

	for( i = 0; i < nrow; i++)
	{
		//int n = strlen(plainText[i]);
		for (j = 0; plainText[i][j] != '\0'; j++)
		{
			plainText[i][j] = tolower(plainText[i][j]);
			if ( plainText[i][j] == ' ')
			{
				index = 27;
				writer << occurence[index][rand()%letterCount[index]];
			}
			else
			{
				index = (plainText[i][j] - 'a') + 1;
				writer << occurence[index][rand()%letterCount[index]];
			}
			writer << ' ';
		}
		writer << endl;
	}
}


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that takes the cipherText(numbers), the count of numbers,
 * the sequence number of letter occurences and the output file handle
 * to decrypt the cipherText and print the plaintext to output file.
 *
 * @param[in] number - array that holds the number read in from file.
 * @param[in] size - number of rows in key.
 * @param[in] occurence - # of times a specific character occurs
 * @param[in] writer - output file stream
 * 
 * @returns nothing
 *
 *
 ******************************************************************************/

void decrypt(int number[], int size, int occurence[][MAXSIZE], ofstream &writer)
{
	int i, j, k = 0;

	for( i = 0; i < size; i++)
	{
		for (j = 0; occurence[i][j]; j++)
		{
			for(k = 1; k < 28; k++)
			{
				if ( number[i] == occurence[k][j])
				{
					if(k == 28)
					writer << ' ';
				
				else
				{
					writer << char((k - 1) + 'a');
				}
				break;
				}
			}
		}
	}
}


/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * This is the main function of the program.  It will call the other functions.
 *
 *
 * @returns 0 - completed successfully
 * @returns 1 - too many arguments given
 * @returns 2 - too few arguments given
 * @returns 3 - incorrect operation
 * @returns 4 - not enough char's in key
 * @returns 5 - cannot open input
 * @returns 6 - cannot open key
 * @returns 7 - cannot open output
 *
 ******************************************************************************/

int main (int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	ifstream reader;
	ofstream writer;
	char text[MAXSIZE][MAXSIZE];
	int nrow = 0;
	int textrow = 0;
	int keyrow = 0;
	int number[MAXSIZE];
	int size;
	char key[MAXSIZE][MAXSIZE];
	int letterCount[MAXSIZE] = {0};
	int occurence[MAXSIZE][MAXSIZE];
	bool ok;
	char infile_name[MAXSIZE];
	char outfile_name[MAXSIZE];

	strcpy(infile_name, argv[2]);
	strcpy(outfile_name, argv[4]);

	if (argc > 5)
	{
		cout << "Too many arguments" << endl;
		return (1);
	}
	if(argc < 5)
	{
		cout << "Not enough arguments";
		return (2);
	}

	cout << argv[0] << endl << argv[1] << endl << argv[2] << endl << argv[3] << endl << argv[4] << endl;

	if(*argv[1] == 'e')
	{
			reader.open(infile_name);
			if (!reader)
			{
				cout << "Unable to open " << infile_name << endl;
				return(5);
			}
			readText(text, textrow, reader);
			reader.close();
	
			reader.open(argv[3]);
			if (!reader)
			{
				cout << "Unable to open " << argv[3] << endl;
				return(6);
			}
			readText(key, nrow, reader);
			ok = findLetter(key, nrow, letterCount, occurence);
			if(ok = false)
			{
				cout << "Not enough characters in key" << endl;
				return(4);
			}
			reader.close();
	
			writer.open(outfile_name);
			if (!writer)
			{
				cout << "Unable to open " << outfile_name << endl;
				return(7);
			}
			encrypt(text, textrow, letterCount, occurence, writer);
			writer.close();
	}
	else if(*argv[1] == 'd')
	{
			reader.open(infile_name);
			if (!reader)
			{
				cout << "Unable to open " << infile_name << endl;
				return(5);
			}
			readNumber(number, size, reader);
			reader.close();
	
			reader.open(argv[3]);
			if (!reader)
			{
				cout << "Unable to open " << argv[3] << endl;
				return(6);
			}
			readText(key, nrow, reader);
			ok = findLetter(key, nrow, letterCount, occurence);
			if(ok = false)
			{
				cout << "Not enough characters in key" << endl;
				return(4);
			}
			reader.close();
	
			writer.open(outfile_name);
			if (!writer)
			{
				cout << "Unable to open " << outfile_name << endl;
				return(7);
			}
			decrypt(number, size, occurence, writer);
			writer.close();
	}
	else
	{
		cout << "Incorrect operation entered.  Enter -e or -d only" << endl;
		return (3);
	}

	return (0);
}
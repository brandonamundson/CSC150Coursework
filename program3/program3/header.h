//constants.h
// This file contains constant declarations
// and function prototypes for the 
// Simple cipher program.
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//Named Constants

/*! 
 * @brief MAXSIZE represents maximium number of characters per 
			line and maximium number of lines per text file
			This is use in the declarations of the plaintext and 
			the key 2D char arrays (both row and column dimensions size).
 */
const int MAXSIZE = 100;

/*! 
 * @brief CHARSETSIZE represents number of unique encryptable character 
			including 24 lowercase letter and whitespace. 
			This is use in the declarations of the occurence 2D array 
			(row dimension size) and the letterCount 1D array (size).
 */
const int CHARSETSIZE = 27;

//Function Prototypes

//Function that takes input file handle and read the contents of the text file,
//  store them into text 2D array, and keep the number of lines in nrow.
void readText(char text[][MAXSIZE],int & nrow, ifstream & reader);

//Function that takes input file handle and read the contents of the number file,
//  store them into number 1D array, and keep the count of numbers in size.
void readNumber(int number[], int & size, ifstream & reader);

//Function that takes the key 2D array, the number of row of 
//  the key array to fill the occurence 2D array with letter sequence numbers
//  and fill the letterCount 1D array with the occurence counts of the 27
//  encryptable characters.
bool findLetter(char key[][MAXSIZE], int nrow, int letterCount[], int occurence[][MAXSIZE]);

//Function that takes the plainText, the number of row of the plainText 2D array,
//  the letterCount, the sequence number of letter occurences and the output file handle
//  to encrypt the plaintext and print the ciphertext(numbers) to the output file.
void encrypt(char plainText[][MAXSIZE], int nrow, int letterCount[], int occurence[][MAXSIZE], ofstream & writer);

//Function that takes the cipherText(numbers), the count of numbers,
//  the sequence number of letter occurences and the output file handle
//  to decrypt the cipherText and print the plaintext to output file.
void decrypt(int number[], int size, int occurence[][MAXSIZE], ofstream & writer);


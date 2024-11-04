//constants.h
// This file contains constant declarations
// and function prototypes for the 
// Extended Newton's Method program.

//Named Constants

/*! 
 * @brief START Represents the beginning of the overall search interval
 */
const double START = -3;

/*! 
 * @brief FINISH Represents the end of the overall search interval
 */
const double FINISH = 4;

/*! 
 * @brief STEP Represents the size of each sub-interval
 */
const double STEP = 0.3;

/*! 
 * @brief  N_ITER Represents the maximum number of iterations
			  that will be used in Newton's Method
 */
const int N_ITER = 50;

/*! 
 * @brief TOLERANCE Represents the error tolerance that will
		  be used in Newton's Method
 */
const double TOLERANCE = .0001;

/*! 
 * @brief MAX_DEGREE Used to create arrays to hold the 
		polynomial equations.  The polynomials for
		this program can have no more than 
		10 terms.
 */
const int MAX_DEGREE = 10;

//Function Prototypes

//Function that gets the input from the user, and returns 
//  a status value to indicate whether there has been 
//  an input error.
int get_function_coefficients(double coeff[], int &degree);

//Function that takes the original equation 
// and computes the equation's derivative
void compute_derivative(double coeff[], double derivative[], int degree);

//Function that computes and returns the value of f(x)
double f(double x, double coeff[], int degree);

//Function that computes and returns the value of f'(x)
double f_prime (double x, double derivative[], int degree); 

//Function that takes the original equation, the derivative, the 
// start and end values, and uses Newton's Method to find
// the root within the interval.
double find_root(double x1, double x2, double coeff[], double derivative[], int degree);
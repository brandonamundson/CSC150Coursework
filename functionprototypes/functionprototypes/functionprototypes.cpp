#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

//function prototypes******************************
int compute_i_loop(int n);
int compute_i_formula (int n);
void compute_i_sqr_loop (int n, int &result);
void compute_i_sqr_formula (int n, int &result);
int compute_i_cubed_loop (int n);
int compute_i_cubed_formula (int n);
int compute_n_factorial (int n);


//functions
int main ()
{
	int n;
	int result;
	int result1;
	int result2;
	
	cout << "Please input n   ";
	cin >> n;
	cout << endl;

	result1 = compute_i_loop(n);
	result2 = compute_i_formula(n);

	cout << "the loop outputs  " << result1 << endl << "the formula outputs  " << result2 << endl;

	if (result1 == result2)
		cout << "Formula is correct for i" << endl << endl;
	else
		cout << "Check formula for i" << endl << endl;

	compute_i_sqr_loop(n, result1);
	compute_i_sqr_formula(n, result2);

	cout << "the loop outputs  " << result1 << endl << "the formula outputs  " << result2 << endl;

	if (result1 == result2)
		cout << "Formula is correct for i squared" << endl << endl;
	else
		cout << "Check formula for i squared" << endl << endl;

	result1 = compute_i_cubed_loop(n);
	result2 = compute_i_cubed_formula(n);

	cout << "the loop outputs  " << result1 << endl << "the formula outputs  " << result2 << endl;

	if (result1 == result2)
		cout << "Formula is correct for i cubed" << endl << endl;
	else
		cout << "Check formula for i cubed" << endl << endl;

	result = compute_n_factorial(n);
	cout << "n factorial is " << result << endl << endl;

	return (0);
}

int compute_i_loop(int n)
{
	int i = 1;
	int sum = 0;
	while ( i <= n)
	{
		sum = sum + i;
		i++;
	}
	return (sum);
}
int compute_i_formula (int n)
{
	int result;
	result = n * (n + 1) / 2;
		return (result);
}
void compute_i_sqr_loop (int n, int &result)
{
	int i = 1;
	result = 0;
	while ( i <= n)
	{
		result = (i * i) + result;
		i++;
	}

}
void compute_i_sqr_formula (int n, int &result)
{
	result = n * (n + 1) * (2 * n + 1);
	result = result/6;
}
int compute_i_cubed_loop (int n)
{
	int i = 1;
	int sum = 0;
	while ( i <= n)
	{
		sum = (i * i * i) + sum;
		i++;
	}
	return (sum);

}
int compute_i_cubed_formula (int n)
{
	int result;
	int temp;

	result = n * n;
	temp = (n + 1) * (n + 1);
	result = (result * temp) / 4;
	return (result);
}
int compute_n_factorial (int n)
{
	int i = 1;
	int compute = 1;
	
	while ( i <= n)
	{
		compute = i * compute;
		i++;
	}
	return (compute);
}

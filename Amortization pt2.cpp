
// Spring 2019

#include <iostream> 
#include <cmath> 
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int length(double n) // number of spaces needed to print a number with commas and two                                                 
					 // decimal places 
{ 
	if (n >= 10)
	{
		int d = log10(n);   
		return d + d / 3 + 4;
	}
	else
		return 4;
}

void commaNumber(ofstream& o, double x) {
	int n, f; // n is integer part and f is the fraction 

	x = round(x * 100) / 100; // round the dollar amount to the nearest cent 
	//int
	n = x;

		int remainder = n % 1000;
		int fval = n / 1000;
		if (remainder <10&& n>=1000){
			o << fval << "," << "00" << remainder;
		}
		if (remainder >=10 && remainder < 100&& n>=1000) {
			o << fval << "," << "0" << remainder;
		}
		else if (remainder > 100&& n >=1000){
			o << fval << "," << remainder;
		}
	if (n < 1000) {
		o << n;
	}
	//fraction
	f = (x - n)* 100;
	if (f >=10) {
		o << "." << f;

	}

	else if (f < 10) {
		o << "." <<"0"<< f;
	}


}
void blanks(ofstream& o, int n)  
// print n number of blanks to output o 
{  
	for (int i = 1; i <= n; i++)   
		o << " "; 
} 
void printDollarNumber(ofstream& o, double x, int s, int c)
// x is the number, s is the 
// total number of spaces, c is position - 1 for left, 2 for center, 3 for  // right-justified 
{
	int b = s - length(x);
	int h = b / 2;
	switch (c)
	{
	case 1:
		commaNumber(o, x);
		blanks(o, b);
		break;
	case 2:
		blanks(o, h);
		commaNumber, (o, x);
		blanks(o, b - h);
		break;
	case 3:
		blanks(o, b);
		commaNumber(o, x);
		break;
	default:
		cout << "Wrong code" << endl;
		break;
	}
}
int main()
{
	const int SPACE = 12;

	double loanAmount, intRate, addtlPrincipal;
	int years;
	do
	{
		cout << "Enter Loan amount (0-9999999), for example 300000.90: ";
		cin >> loanAmount;
	} while ((loanAmount <= 0) || (loanAmount > 9999999));
	do
	{
		cout << "Enter annual interest rate(0-50), for example 4.25 meaning 4.25%: ";
		cin >> intRate;
	} while ((intRate <= 0) || (intRate > 50));
	do
	{
		cout << "Enter no. of years as integer(1-50), for example 30: ";
		cin >> years;
	} while ((years < 1) || (years > 50));
	do
	{
		cout << "Enter additional principal per month (0-9999999), for example 300: ";
		cin >> addtlPrincipal;
	} while ((addtlPrincipal < 0) || (addtlPrincipal > 9999999));
	string fileName;

	cout << "Send the mortgage amortization table to a file (enter file name): ";  cin >> fileName;

	ofstream outFile(fileName);

	double monIntRate = intRate / 1200;
	int term, termtot = years * 12;
	double mthlyPymt = loanAmount * monIntRate / (1 - 1 / pow(1 + monIntRate, termtot));
	double actPymt = mthlyPymt + addtlPrincipal;
	double balance = loanAmount;
	double interest;
	double principal;
	

	outFile << endl << endl;
	outFile << "\n\t MORTGAGE AMORTIZATION TABLE" << endl;
	outFile << "\nAmount:\t\t\t" << "$";
	printDollarNumber(outFile, loanAmount, SPACE, 3);
	outFile << endl;
	outFile << "Interest Rate:\t\t" << intRate << "%" << endl;
	outFile << "Term(Years):\t\t" << years << endl;
	outFile << "Monthly Payment:\t\t" << "$";
	printDollarNumber(outFile, mthlyPymt, SPACE, 3);
	outFile << endl;
	outFile << "Additonal Principal:\t" << "$";
	printDollarNumber(outFile, addtlPrincipal, SPACE, 3);
	outFile << endl;
	outFile << "Actual Payment:\t\t" << "$";
	printDollarNumber(outFile, actPymt, SPACE, 3);
	outFile << endl << endl;
	outFile << "\t";
	blanks(outFile, SPACE - 9);
	outFile << "Principal\t";
	blanks(outFile, SPACE - 8);
	outFile << "Interest\t";
	blanks(outFile, SPACE - 7);
	outFile << "Balance" << endl;
	for (term = 1, term <= termtot; term++;) {
		interest = monIntRate * balance;
		principal = actPymt - interest;
		balance -= principal;
		if (balance <= 0) {
			balance -= balance;
			outFile << "\n" << term;
			outFile << "\t";
			outFile << "$";
			outFile << "\t";
			printDollarNumber(outFile, principal, SPACE, 3);
			
			outFile << "$";
			outFile << "\t";
			printDollarNumber(outFile, interest, SPACE, 3);
			
			outFile << "$";
			outFile << "\t";
			printDollarNumber(outFile, balance, SPACE, 3);
	
			system("pause");
			return 0; 
		}
		else
		outFile << "\n" << term;
		outFile << "\t";
		outFile << "$"; 
		outFile << "\t";
		printDollarNumber(outFile,principal,SPACE,3);
		outFile << "$";
		outFile << "\t";
			printDollarNumber(outFile, interest, SPACE, 3); 
		outFile << "$";
		outFile << "\t";
			printDollarNumber(outFile, balance, SPACE, 3); 
	}
	outFile.close();
	system("pause");
	return 0;
}
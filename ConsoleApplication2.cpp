#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double monthlyPayment, loanAmount, annualInterest, Balance, Actualpayment, Interest, principal, Addprincipal;
	int numberOfYears;
	cout << "Please enter the number of years:\n";
	cin >> numberOfYears;
	//Years converted to months
	int terms = numberOfYears * 12;
	cout << "please enter the amount of additional principal:\n";
	cin >> Addprincipal;

	cout << "Please enter the annual interest rate:\n";
	cin >> annualInterest;
	double monthlyir = annualInterest / 12;

	cout << "Please enter the Loan Amount:\n";
	cin >> loanAmount;

	if (annualInterest = 0) {
		monthlyPayment = loanAmount / terms;
	}
	else {
		monthlyPayment = (loanAmount * monthlyir) / (1 - 1 / pow(1 + monthlyir, terms));
	}
	//formulas
	Actualpayment = monthlyPayment + Addprincipal;
	principal = Actualpayment - (loanAmount * monthlyir);
	Balance = loanAmount - principal;
	Interest = Balance * monthlyir;

	//display 
	cout << fixed << showpoint;
	cout << "Monthly Payment:$" << monthlyPayment;
	cout << "Actual Payment:$\t" << Actualpayment;
	cout << "Term\t";
	cout << "Balance:";

	for (int term = 1; term <= terms; term++) {

	}

	return 0;

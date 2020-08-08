#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main() {
	//Variables
	double monthlyPayment, loanAmount, monthlyIr, term, actualPayment, Principal, addPrincipal, Bal, annualIr, Interest, termtot;
	int numberOfyears;
	{
		cout << "Please enter the loan amount:\n" << "$";
		cin >> loanAmount;
		while (loanAmount >= 9999999.00) {
			cout << "invalid amount";
			cout << endl;
			cout << "Please enter the loan amount:\n" << "$";
			cin >> loanAmount;
		}
		cout << "Please enter the number of years:\n";
		cin >> numberOfyears;
		while (numberOfyears <= 0 || numberOfyears >= 40) {
			cout << "invalid number of years";
			cout << endl;
			cout << "Please enter the number of years:\n";
			cin >> numberOfyears;
		}
		cout << "Please enter the annual interest rate:\n";
		cin >> annualIr;
		while (annualIr <= 0) {
			cout << "invalid rate";
			cout << endl;
			cout << "Please enter the annual interest rate:\n" << "%";
			cin >> annualIr;
		}
		cout << "Please enter the additional principal:\n" << "$";
		cin >> addPrincipal;
		while (addPrincipal < 0) {
			cout << "invalid principal";
			cout << endl;
			cout << "Please enter the additional principal:\n";
			cin >> addPrincipal;
		}
		
		monthlyIr = annualIr / 100 / 12.0;
		termtot = numberOfyears * 12;
		//formula
		monthlyPayment = (loanAmount * monthlyIr) /
			(1 - 1 / pow(1 + monthlyIr, termtot));
		actualPayment = monthlyPayment + addPrincipal;
		//display header
		cout << endl;
		cout << "Amount:" << "\t\t\t $ ";
		cout << setprecision(2) << fixed << loanAmount << "\n";
		cout << "Term(Years):" << "\t\t\t " << numberOfyears << "\n";
		cout << "Interest Rate:" << "\t\t % " << annualIr << "\n";
		cout << "Monthly Payment:" << "\t $ "<< monthlyPayment << "\n";
		cout << "Additional Principal:" << "\t $ " << addPrincipal;
		cout << "\n";
		cout << "Actual Payment:" << "\t\t $ " << actualPayment << "\n";
		cout << endl;
		//table header display
		cout << "Term\t" << "Principal\t" << "Interest\t" << "Balance\t";
		//loop
		Bal = loanAmount;
		for (term = 1; term <= termtot; term++) {

			Interest = monthlyIr * Bal;
			Principal = actualPayment - Interest;
			Bal = Bal - Principal;
			//for last payment
			if (Bal <= 0) {
				Bal = Bal - Bal;
				cout << setprecision(0) << "\n" << term;
				cout << setprecision(2);
				cout << "\t" << "$" << Principal << "\t" << Interest << "\t\t" << "$" << Bal;
				cout << endl;
				cout << "BALANCE HAS BEEN PAID";
				return 0;
			}// display for figures
			else {
				cout << setprecision(0) << "\n" << term;
				cout << setprecision(2);
				cout << "\t" << "$" << Principal << "\t" << Interest << "\t\t" << "$" << Bal;
				cout << endl;

			}
		}
	}
			return 0;
	}

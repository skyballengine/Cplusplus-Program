#include <iostream>
#include <string>
#include <iomanip>
#include "BankingApp.h"

using namespace std;
	// data members
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int termYears;
	double finalTotal;
	double finalTotal_noMonthly;
	const int months = 12;
	
	//default constructor with default values of 0
	BankingApp::BankingApp() {
		this->initialInvestment = 0;
		this->monthlyDeposit = 0;
		this->annualInterest = 0;
		this->termYears = 0;
		this->finalTotal = 0;
		this->finalTotal_noMonthly = 0;
	}

	// Menu display and input member function
	void BankingApp::MenuInput() {
		//bool exitKey = false;

		//FIXME:Couldn't get loop to run properly also couldn't get the input validation to catch if cin.fail() occurred
		// it would loop infinitely and the if statement wouldn't catch the error
		
		//while (exitKey == false) {
			cout << setfill('*') << setw(30) << "" << endl;
			cout << setw(9) << setfill('*') << "";
			cout << " Data Input ";
			cout << setw(9) << setfill('*') << "" << endl;
			cout << setfill('*') << setw(30) << "" << endl;

			cout << "Initial Investment Amount: ";
			cin >> this->initialInvestment;
			if (/*cin.fail() || */this->initialInvestment < 0) {
				cout << "Value is of wrong type or a value below zero. Please enter a positive number." << endl;
				cout << endl;
				MenuInput();
				//break;
			}

			cout << "Monthly Deposit: ";
			cin >> this->monthlyDeposit;
			if (/*cin.fail() || */this->monthlyDeposit < 0) {
				cout << "Value is of wrong type or a value below zero. Please enter a positive number." << endl;
				cout << endl;
				MenuInput();
				//break;
			}

			cout << "Annual Interest: ";
			cin >> this->annualInterest;
			if (/*cin.fail() || */this->annualInterest < 0) {
				cout << "Value is of wrong type or a value below zero. Please enter a positive number." << endl;
				cout << endl;
				MenuInput();
				//break;
			}

			cout << "Number of years: ";
			cin >> this->termYears;
			if (/*cin.fail() || */this->termYears < 0) {
				cout << "Value is of wrong type or a value below zero. Please enter a positive number." << endl;
				cout << endl;
				MenuInput();
				//break;
			}

			/*cout << "Press any key to continue....." << endl;
			cin >> exitKey;
			if (cin.good()) {
				exitKey == true;
			}*/
		//}
		//MenuInput();
		
	}

	
	// Input computing function
	double BankingApp::ComputeAndDisplay() { 

		double tempValue;
		double tempValue2;
		unsigned int i = 0;
		unsigned int j = 0;
		unsigned int k = 0;
		int yearCount;
		double annualInterest_noMonthly;
		double annualInterest_withMonthly;
		//double monthlyIncrement;

		// sets fixed point notation at 2 decimals
		cout << setprecision(2) << fixed;

		// Table display for WITHOUT monthly deposits
		cout << endl;
		cout << setfill('=') << setw(56) << "" << endl;
		cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << setfill('=') << setw(56) << "" << endl;
		cout << setfill(' ');

		// Display the current object's data members
		this->PrintBankingObj();
		cout << setfill('-') << setw(56) << "" << endl;
		cout << setfill(' ');

		cout << "  " << setw(7) << left << "Year" << "";
		cout << setw(22) << left << "Year End Balance" << "";
		cout << setw(32) << left << "Year End Earned Interest" << endl;
		cout << setfill('-') << setw(56) << "" << endl;
		cout << setfill(' ');


		// loop for annual reports WITHOUT monthly deposits
		this->finalTotal_noMonthly = this->initialInvestment;
		yearCount = 0;
		for (k = 0; k < this->termYears; ++k) {

			// loop without monthly deposits
			annualInterest_noMonthly = 0;
			for (j = 0; j < months; ++j) {
 
				tempValue2 = (this->finalTotal_noMonthly) * ((this->annualInterest / 100) / 12);
				annualInterest_noMonthly += tempValue2;

				this->finalTotal_noMonthly += tempValue2;
				
			}
			// increment years for table display
			++yearCount;

			cout << setw(6) << right << yearCount << "";
			cout << setw(19) << right << this->finalTotal_noMonthly << "";
			cout << setw(30) << right << annualInterest_noMonthly << endl;
			cout << endl;

		}

		// Table display for WITH monthly deposits
		cout << endl;
		cout << setfill('=') << setw(56) << "" << endl;
		cout << "Balance and Interest With Additional Monthly Deposits" << endl;
		cout << setfill('=') << setw(56) << "" << endl;
		cout << setfill(' ');

		// Display the current object's data members
		this->PrintBankingObj();
		cout << setfill('-') << setw(56) << "" << endl;
		cout << setfill(' ');

		cout << "  " << setw(7) << left << "Year" << "";
		cout << setw(22) << left << "Year End Balance" << "";
		cout << setw(32) << left << "Year End Earned Interest" << endl;
		cout << setfill('-') << setw(56) << "" << endl;
		cout << setfill(' ');

		// loop for annual reports WITH monthly deposits
		this->finalTotal = this->initialInvestment;
		yearCount = 0;
		for (k = 0; k < this->termYears; ++k) {

			// loop with monthly deposits
			annualInterest_withMonthly = 0;
			for (i = 0; i < months; ++i) {

				tempValue = (this->finalTotal + (this->monthlyDeposit));
				annualInterest_withMonthly += tempValue * ((this->annualInterest / 100) / 12);
				tempValue = tempValue + (tempValue * ((this->annualInterest / 100) / 12));

				this->finalTotal = tempValue;
			}
			// increment years for table display
			++yearCount;

			cout << setw(6) << right << yearCount << "";
			cout << setw(19) << right << this->finalTotal << "";
			cout << setw(30) << right << annualInterest_withMonthly << endl;
			cout << endl;

		}

		// Used for testing purposes 
		/*cout << "Monthly" << endl;
		cout << "Total with $" << this->monthlyDeposit << " monthly contributions: " << this->finalTotal << endl;
		cout << endl;
		cout << "No Monthly" << endl;
		cout << "Total with no monthly contributions: " << this->finalTotal_noMonthly << endl;
		cout << endl;*/

		return 0;
	}

	void BankingApp::PrintBankingObj() { // For comparing final values and checking with user if they entered the correct values
		cout << "Initial Investment: " << this->initialInvestment << endl;
		cout << "Monthly Deposit: " << this->monthlyDeposit << endl;
		cout << "Annual Interest: " << this->annualInterest << " %" << endl;
		cout << "Term in years: " << this->termYears << endl;
	}



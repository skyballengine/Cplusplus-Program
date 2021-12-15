#include <iostream>
#include <string>
#include <iomanip>
#include "BankingApp.h"

using namespace std;

int main() {
	double total = 0;
	char userInput;
	bool runProgram = true;

	// Instantiate a BankingApp object
	BankingApp numbers1;

	// Program loop (run while runProgram is true)
	while (runProgram) {
		numbers1.MenuInput();
		// Print a summary of what the user input
		cout << endl;
		cout << setfill('*') << setw(30) << "" << endl;
		cout << "You have entered the following: " << endl;
		numbers1.PrintBankingObj();
		cout << setfill('*') << setw(30) << "" << endl;
		cout << endl;

		// Check if they would like to change values
		cout << "If you would like to change the values, please press 'y' or 'n' to continue." << endl;
		cin >> userInput;
		// validate input
		while (userInput != 'N' && userInput != 'n') {
			numbers1.MenuInput();

			cout << "Would you like to enter new values? (Press 'y' if you would like to rerun the program with new values)." << endl;
			cin >> userInput;
		}
		// compute and display the entered values
		numbers1.ComputeAndDisplay();

		// check if user would like to run the program again
		cout << "Would you like to run the program again? Enter 'y' for yes or 'n' for no." << endl;
		cin >> userInput;
		if (userInput == 'Y' || userInput == 'y') {
			runProgram = true;
		}
		else if (userInput == 'N' || userInput == 'n') {
			runProgram = false;
		}
		else {
			cout << "Invalid response. Please enter 'y' for yes or 'n' for no. " << endl;
			cin >> userInput;
		}
	}


	return 0;
}

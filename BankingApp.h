#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankingApp {
	public:
		BankingApp();
		void MenuInput();
		double ComputeAndDisplay();
		void PrintBankingObj(); 


		double initialInvestment;
		double monthlyDeposit;
		double annualInterest;
		int termYears;
		double finalTotal;
		double finalTotal_noMonthly;
		const int months = 12;


};

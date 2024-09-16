#include <iostream>
#include <iomanip>
#include <string>
#include "highInterestSavingsType.h"
using namespace std;

const double highInterestSavingsType::MINIMUM_BALANCE = 2500.00;
const double highInterestSavingsType::INTEREST_RATE = 0.005;

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal)
							: savingsAccountType(n, acctNumber, bal, INTEREST_RATE)
{
	minimumBalance = MINIMUM_BALANCE;
}

highInterestSavingsType::highInterestSavingsType(string n, int acctN, double balance, double intRate, double minBalance)
							: savingsAccountType(n, acctN, balance, intRate)
{
	minimumBalance = minBalance;
}

double highInterestSavingsType::getMinimumBalance(){
	return minimumBalance;
}

bool highInterestSavingsType::verifyMinimumBalance(double amount) {
	return (getBalance() - amount >= minimumBalance);
}

void highInterestSavingsType::withdraw(double amount){
	if (verifyMinimumBalance(amount))
		balance = getBalance() - amount;
}

void highInterestSavingsType::print() {
	cout << fixed << showpoint << setprecision(2);
	cout << "High Interest Savings: " << getName() << "\t ACCT# " << getAccountNumber() << "\t Balance: $" << getBalance();
}

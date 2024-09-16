#include <iostream>
#include <iomanip>
#include <string>
#include "certificateOfDepositType.h"
using namespace std;

const double certificateOfDepositType::INTEREST_RATE = 0.05;
const int certificateOfDepositType::NUMBER_OF_MATURITY_MONTHS = 6;

certificateOfDepositType::certificateOfDepositType(string n, int acctNumber, double bal)
							: bankAccountType(n, acctNumber, bal)
{
	interestRate = INTEREST_RATE;
	maturityMonths = 0;
	cdMonth = 0;
}

certificateOfDepositType::certificateOfDepositType(string n, int acctNumber, double bal, double intRate, int maturityMon)
							: bankAccountType(n,acctNumber, bal)
{
	interestRate = intRate;
	maturityMonths = maturityMon;
	cdMonth = 0;
}

double certificateOfDepositType::getInterestRate() {
	return interestRate;
}

void certificateOfDepositType::setInterestRate(double rate){
	interestRate = rate;
}

double certificateOfDepositType::getCurrentCDMonth() {
	return cdMonth;
}

void certificateOfDepositType::setCurrentCDMonth(int month) {
	cdMonth = month;
}

int certificateOfDepositType::getMaturityMonths() {
	return maturityMonths;
}

void certificateOfDepositType::getMaturityMonths(int month){
	maturityMonths = month;
}


void certificateOfDepositType::postInterest() {
	balance = balance + balance * interestRate;
}

void certificateOfDepositType::withdraw(double /*amount*/) {
 /// no code
}


void certificateOfDepositType::withdraw() {
	if (cdMonth > maturityMonths)
		balance = 0;
	else
		cout << "CD has not been matured. No withdrawal." << endl;
}
void certificateOfDepositType::createMonthlyStatement() {
	postInterest();
	cdMonth++;
}

void certificateOfDepositType::print() {
	cout << fixed << showpoint << setprecision(2);
	cout << "certificate of Deposit: " << getName() << "\t ACCT# " << getAccountNumber() << "\tBalance: $" << getBalance();
}

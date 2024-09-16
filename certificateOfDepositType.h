#ifndef certificateofDepositType_H
#define certificateofDepositType_H

#include "bankAccountType.h"
#include <iostream>
using namespace std;

class certificateOfDepositType: public bankAccountType {

public:
	certificateOfDepositType(string n, int acctNumber, double bal);
	certificateOfDepositType(string n, int acctNumber, double bal, double intRate, int maturityMon);
	double getInterestRate();
	void setInterestRate(double rate);
	double getCurrentCDMonth();
	void setCurrentCDMonth(int month);
	int getMaturityMonths();
	void getMaturityMonths(int month);
	void postInterest();
	void withdraw(double ammount);
	void withdraw();
	void createMonthlyStatement();
	void print();

private:
	static const double INTEREST_RATE; // 0.005
	static const int NUMBER_OF_MATURITY_MONTHS; //6

	double interestRate;
	int maturityMonths;
	int cdMonth;
};

#endif

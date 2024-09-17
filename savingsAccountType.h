#ifndef SAVINGS_ACCOUNT_TYPE_H
#define SAVINGS_ACCOUNT_TYPE_H

#include "bankAccountType.h"
#include <string>

using namespace std;

class savingsAccountType : public bankAccountType {
public:
    savingsAccountType(string n, int acctNumber, double bal, double intRate);
    double getInterestRate() const;
    void setInterestRate(double rate);
    void postInterest();
    void createMonthlyStatement() override;
    void print() override;
    string getType() const override { return "Savings"; }

protected:
    double interestRate;
};

#endif // SAVINGS_ACCOUNT_TYPE_H

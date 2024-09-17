#ifndef HIGH_INTEREST_SAVINGS_TYPE_H
#define HIGH_INTEREST_SAVINGS_TYPE_H

#include "savingsAccountType.h"
#include <string>

using namespace std;

class highInterestSavingsType : public savingsAccountType {
public:
    highInterestSavingsType(string n, int acctNumber, double bal);
    double getMinimumBalance() const;
    bool verifyMinimumBalance(double amount);
    void withdraw(double amount) override;
    void print() override;
    string getType() const override { return "High Interest Savings"; }

private:
    static const double MINIMUM_BALANCE;
    static const double INTEREST_RATE;
    double minimumBalance;
};

#endif // HIGH_INTEREST_SAVINGS_TYPE_H

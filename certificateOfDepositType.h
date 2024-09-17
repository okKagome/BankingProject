#ifndef CERTIFICATE_OF_DEPOSIT_TYPE_H
#define CERTIFICATE_OF_DEPOSIT_TYPE_H

#include "bankAccountType.h"
#include <string>

using namespace std;

class certificateOfDepositType : public bankAccountType {
public:
    certificateOfDepositType(string n, int acctNumber, double bal);
    certificateOfDepositType(string n, int acctNumber, double bal, double intRate, int maturityMon);
    double getInterestRate() const;
    void setInterestRate(double rate);
    double getCurrentCDMonth() const;
    void setCurrentCDMonth(int month);
    int getMaturityMonths() const;
    void setMaturityMonths(int month);
    void postInterest();
    void withdraw(double amount) override;
    void withdraw();
    void createMonthlyStatement() override;
    void print() override;
    string getType() const override { return "Certificate of Deposit"; }

private:
    static const double INTEREST_RATE;
    static const int NUMBER_OF_MATURITY_MONTHS;

    double interestRate;
    int maturityMonths;
    int cdMonth;
};

#endif // CERTIFICATE_OF_DEPOSIT_TYPE_H

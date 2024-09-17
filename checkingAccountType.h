#ifndef CHECKING_ACCOUNT_TYPE_H
#define CHECKING_ACCOUNT_TYPE_H

#include "bankAccountType.h"

using namespace std;

class checkingAccountType : public bankAccountType {
public:
    checkingAccountType(string n, int acctNumber, double bal);
    virtual void writeCheck(double amount) = 0;
    string getType() const override { return "Checking"; }
};

#endif // CHECKING_ACCOUNT_TYPE_H

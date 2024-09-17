#ifndef BANK_ACCOUNT_TYPE_H
#define BANK_ACCOUNT_TYPE_H

#include <string>

using namespace std;

class bankAccountType {
protected:
    string name;
    int accountNumber;
    double balance;

public:
    bankAccountType(string n = "", int acctNumber = 0, double bal = 0);
    int getAccountNumber() const;
    double getBalance() const;
    string getName() const;
    void setName(string n);
    void setBalance(double bal);
    virtual void withdraw(double amount);
    void deposit(double amount);
    virtual void createMonthlyStatement() = 0;
    virtual void print();
    virtual string getType() const = 0;
};

#endif // BANK_ACCOUNT_TYPE_H

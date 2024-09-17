#include "bankAccountType.h"
#include <iostream>
#include <iomanip>

using namespace std;

bankAccountType::bankAccountType(string n, int acctNumber, double bal) {
    name = n;
    accountNumber = acctNumber;
    balance = bal;
}

int bankAccountType::getAccountNumber() const {
    return accountNumber;
}

double bankAccountType::getBalance() const {
    return balance;
}

string bankAccountType::getName() const {
    return name;
}

void bankAccountType::setName(string n) {
    name = n;
}

void bankAccountType::setBalance(double bal) {
    balance = bal;
}

void bankAccountType::withdraw(double amount) {
    balance = balance - amount;
}

void bankAccountType::deposit(double amount) {
    balance = balance + amount;
}

void bankAccountType::print() {
    cout << fixed << showpoint << setprecision(2);
    cout << name << " " << accountNumber << " Balance : $" << balance;
}

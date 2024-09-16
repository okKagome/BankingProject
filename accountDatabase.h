#ifndef ACCOUNT_DATABASE_H
#define ACCOUNT_DATABASE_H

#include <vector>
#include <memory>
#include "bankAccountType.h"

using namespace std;

void saveAccount(const unique_ptr<bankAccountType>& account);
vector<unique_ptr<bankAccountType>> loadAccounts();
int getNextAccountNumber();
bool removeAccountFromDatabase(int accountNumber);
bool updateAccountInDatabase(const bankAccountType& account);

#endif // ACCOUNT_DATABASE_H

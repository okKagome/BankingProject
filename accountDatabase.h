#ifndef ACCOUNT_DATABASE_H
#define ACCOUNT_DATABASE_H

#include <vector>
#include <memory>
#include "bankAccountType.h"

using namespace std;

void saveAccount(const unique_ptr<bankAccountType>& account);
vector<unique_ptr<bankAccountType>> loadAccounts();
int getNextAccountNumber();

#endif // ACCOUNT_DATABASE_H

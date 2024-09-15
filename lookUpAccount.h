#ifndef LOOK_UP_ACCOUNT_H
#define LOOK_UP_ACCOUNT_H

#include "bankAccountType.h"
#include <memory>

std::unique_ptr<bankAccountType> lookUpAccount();

#endif // LOOK_UP_ACCOUNT_H

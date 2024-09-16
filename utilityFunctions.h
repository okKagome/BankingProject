#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <string>

void clearScreen();
double getValidAmount(const char* prompt = "Enter amount: $");
int getValidInteger(const char* prompt = "Enter value: ");
std::string toLowerCase(const std::string& str);
std::string getCurrentDate();

#endif // UTILITY_FUNCTIONS_H

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

# Source files
SRCS = main.cpp \
       accountDatabase.cpp \
       createAccount.cpp \
       editAccount.cpp \
       lookUpAccount.cpp \
       utilityFunctions.cpp \
		deposit.cpp \
		withdraw.cpp \
		checkBalance.cpp \
		listAllAccounts.cpp \
		deleteAccount.cpp \
       bankAccountType.cpp \
       checkingAccountType.cpp \
       savingsAccountType.cpp \
       certificateOfDepositType.cpp \
       serviceChargeCheckingType.cpp \
       noServiceChargeCheckingType.cpp \
       highInterestCheckingType.cpp \
       highInterestSavingsType.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output executable
TARGET = bank_system

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

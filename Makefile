CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
TARGET = bank_system

SOURCES = main.cpp \
          accountDatabase.cpp \
          createAccount.cpp \
          editAccount.cpp \
          lookUpAccount.cpp \
          utilityFunctions.cpp \
          bankAccountType.cpp \
          checkingAccountType.cpp \
          savingsAccountType.cpp \
          certificateOfDepositType.cpp \
          serviceChargeCheckingType.cpp \
          noServiceChargeCheckingType.cpp \
          highInterestCheckingType.cpp \
          highInterestSavingsType.cpp

HEADERS = accountDatabase.h \
          createAccount.h \
          editAccount.h \
          lookUpAccount.h \
          utilityFunctions.h \
          bankAccountType.h \
          checkingAccountType.h \
          savingsAccountType.h \
          certificateOfDepositType.h \
          serviceChargeCheckingType.h \
          noServiceChargeCheckingType.h \
          highInterestCheckingType.h \
          highInterestSavingsType.h

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean

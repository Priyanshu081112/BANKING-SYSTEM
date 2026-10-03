#ifndef ACCOUNT_H
#define ACCOUNT_H

#include"Transaction.h"
#include<vector>

using namespace std;

class Account{
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accountNumber);

    void deposit(double amount);
    void withdraw(double amount);
    void displayAccount();
    void DisplayTransactions();

    int getAccountNumber();
    double getBalance();

};
#endif
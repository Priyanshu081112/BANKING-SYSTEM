#include "Account.h"
#include <iostream>

using namespace std;

Account::Account(int accountNumber)
{
    this->accountNumber = accountNumber;
    balance = 0.0;
}

void Account::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount!" << endl;
        return;
    }

    balance += amount;

    Transaction t(1, "Deposit", amount, "Money deposited");
    transactions.push_back(t);

    cout << "Amount deposited successfully!" << endl;
    cout << "Current Balance: " << balance << endl;
}

void Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid withdrawal amount!" << endl;
        return;
    }

    if (amount > balance)
    {
        cout << "Insufficient balance!" << endl;
        return;
    }

    balance -= amount;

    Transaction t(2, "Withdrawal", amount, "Money withdrawn");
    transactions.push_back(t);

    cout << "Amount withdrawn successfully!" << endl;
    cout << "Current Balance: " << balance << endl;
}

void Account::displayAccount()
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}

int Account::getAccountNumber()
{
    return accountNumber;
}

double Account::getBalance()
{
    return balance;
}

void Account::DisplayTransactions()
{
    cout << "\n==============================" << endl;
    cout << "      TRANSACTION HISTORY     " << endl;
    cout << "==============================" << endl;

    if (transactions.empty())
    {
        cout << "No transactions found." << endl;
        return;
    }

    for (Transaction &t : transactions)
    {
        t.DisplayTransaction();
        cout << "-------------------" << endl;
    }
}
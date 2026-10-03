#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"Account.h"

#include<string>
#include<vector>
using namespace std;

class Customer{
private:
    int CustomerID;
    string Name;
    string Phoneno;
    string Email;
    vector <Account> accounts;

public:
    Customer();

    void CreateCustomer();
    void addAccount(int accountNumber);
    void DepositMoney(int accountNumber,double Amount);
    void WithdrawMoney(int accountNumber,double Amount);
    void TransferMoney(int fromAccountNumber,int toAccountNumber,double Amount);
    void DisplayAccountDetails(int accountNumber);
    void DisplayTransactionsHistory(int accountNumber);
    void DisplayCustomer();
};
#endif
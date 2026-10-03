#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>

using namespace std;

class Transaction{
private:
    int TransactionID;
    string Type;
    double Amount;
    string Description;

public:
    Transaction(int id,string type,double amount,string description);
    void DisplayTransaction();

};

#endif

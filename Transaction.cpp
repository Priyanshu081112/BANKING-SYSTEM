#include "Transaction.h"
#include<iostream>
using namespace std;

Transaction::Transaction(int id,string Type,double Amount,string Description){
    TransactionID=id;
    this->Type=Type;
    this->Amount=Amount;
    this->Description=Description;
}
void Transaction::DisplayTransaction()
{
    cout << "Transaction ID: " << TransactionID << endl;
    cout << "Type: " << Type << endl;
    cout << "Amount: " << Amount << endl;
    cout << "Description: " << Description << endl;
}

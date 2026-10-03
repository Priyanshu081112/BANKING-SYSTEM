#include"Customer.h"
#include<iostream>
using namespace std;

Customer::Customer(){
    CustomerID=0;
    Name="";
    Phoneno="";
    Email="";
}

 void Customer::CreateCustomer(){
    cout<<"\n=========================="<<endl;
    cout<<"       CREATE CUSTOMER"<<endl;
    cout<<"==========================="<<endl;

    cout<<"Enter Customer ID: ";
    cin>>CustomerID;

    cout<<"Enter Name: ";
    cin>>ws;
    getline(cin,Name);

    cout<<"Enter Phone: ";
    cin>>Phoneno;

    cout<<"Enter Email: ";
    cin>>Email;

    cout<<"\nCustomer Created Successfully!\n";
}

void Customer::addAccount(int accountNumber){
    Account newAccount(accountNumber);
    accounts.push_back(newAccount);
    cout << "Account added successfully!" << endl;
}

void Customer::DepositMoney(int accountNumber,double Amount){
    for(Account &a : accounts){
        if(a.getAccountNumber()== accountNumber){
            a.deposit(Amount);
            return;
        }
    }
    cout<<"Account Not Found! "<<endl;
}

void Customer::WithdrawMoney(int accountNumber,double Amount){
    for(Account &a : accounts){
        if(a.getAccountNumber()== accountNumber){
            a.withdraw(Amount);
            return;
        }
    }
    cout<<"Account Not Found!"<<endl;
}

void Customer::TransferMoney(int fromAccountNumber,int toAccountNumber,double Amount){
    Account *fromAccount=nullptr;
    Account *toAccount=nullptr;

    if(fromAccountNumber == toAccountNumber){
        cout<<"Sender and Receiver accounts cannot be same!"<<endl;
        return;
    }

    for(Account &a : accounts){
        if(a.getAccountNumber()==fromAccountNumber){
            fromAccount=&a;
        }
        if(a.getAccountNumber()==toAccountNumber){
            toAccount=&a;
        }
    }
    if(fromAccount==nullptr || toAccount==nullptr){
        cout<<"Account Not Found! ";
        return;
    }
    if(Amount <= 0){
        cout<<"Invalid Amount! "<<endl;
        return;
    }
    if(Amount > fromAccount->getBalance()){
        cout<<"Insufficient Balance!"<<endl;
        return;
    }
    fromAccount->withdraw(Amount);
    toAccount->deposit(Amount);

    cout<<"Money Transferred Successfully!"<<endl;
}

void Customer::DisplayAccountDetails(int accountNumber){
    for(Account &a : accounts){
        if(a.getAccountNumber()==accountNumber){
            a.displayAccount();
            return;
        }
    }
    cout<<"Account Not Found!"<<endl;
}

void Customer::DisplayTransactionsHistory(int accountNumber){
    for(Account &a : accounts){
        if(a.getAccountNumber()==accountNumber){
            a.DisplayTransactions();
            return;
        }
    }
    cout<<"Account Not Found!"<<endl;
}

void Customer::DisplayCustomer(){
    cout << "\n===========================" << endl;
    cout << "     CUSTOMER DETAILS       " << endl;
    cout << "===========================" << endl;

    cout<<"CustomerID: "<<CustomerID<<endl;
    cout<<"Customer Name: "<<Name<<endl;
    cout<<"Phone Number: "<<Phoneno<<endl;
    cout<<"Email: "<<Email<<endl;
    cout<<"\nAccounts: "<<endl;
    
    if (accounts.empty())
    {
        cout << "No accounts found." << endl;
        return;
    }
    for(Account &a : accounts){
        a.displayAccount();
        cout<<"---------------------------"<<endl;
    }

}
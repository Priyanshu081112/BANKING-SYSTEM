#include<iostream>
#include<string>
#include"Customer.h"
using namespace std;

int main(){
    Customer customer;
    int choice;
    while(true){
        cout<<endl;
        cout<<"=============================="<<endl;
        cout<<"        BANKING SYSTEM        "<<endl;
        cout<<"=============================="<<endl;
        cout<<endl;

        cout<<"1. Create Customer"<<endl;
        cout<<"2. Create Account"<<endl;
        cout<<"3. Deposit Money"<<endl;
        cout<<"4. Withdraw Money"<<endl;
        cout<<"5. Transfer Money"<<endl;
        cout<<"6. View Account Details"<<endl;
        cout<<"7. View Transaction History"<<endl;
        cout<<"8. View Customer Details"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<endl;

        cout<<"Enter your choice: ";

        cin>>choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a Number from 1 to 9."<<endl;
            continue;
        }
        switch(choice){
            case 1:
                customer.CreateCustomer();
                break;
            
            case 2:
            {
                int accountNumber;
                cout<<"Enter Account Number: ";
                cin>>accountNumber;

                customer.addAccount(accountNumber);
                break;
            }

            case 3:
            {
                int accountNumber;
                double amount;

                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                cout<<"Enter Amount: ";
                cin>>amount;

                customer.DepositMoney(accountNumber,amount);
                break;
            }

            case 4 :
            {
                int accountNumber;
                double amount;

                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                cout<<"Enter Amount: ";
                cin>>amount;

                customer.WithdrawMoney(accountNumber,amount);
                break;   
            }

            case 5 :
            {
                int fromAccountNumber;
                int toAccountNumber;
                double Amount;

                cout<<"Enter Sender Account Number: ";
                cin>>fromAccountNumber;

                cout<<"Enter Receiver Account Number: ";
                cin>>toAccountNumber;

                cout<<"Enter Amount: ";
                cin>>Amount;

                customer.TransferMoney(fromAccountNumber,toAccountNumber,Amount);
                break;
            }

            case 6 :
            {
                int accountNumber;
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                customer.DisplayAccountDetails(accountNumber);
                break;
            }
            
            case 7 :
            {
                int accountNumber;
                cout<<"Enter Account Number: ";
                cin>>accountNumber;
                customer.DisplayTransactionsHistory(accountNumber);
                break;
            }

            case 8 :
            {
                customer.DisplayCustomer();
                break;
            }

            case 9:
                cout << "\nThank you for using the Banking System!\n ";
                return 0;

            default:
                cout << "Invalid choice ! Please try again.\n";
        }
    
    }
    return 0;
}
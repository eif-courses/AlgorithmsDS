// DatabaseSQLite3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// TOOBOX FOR SQLITE PREVIEW INSIDE VISUAL STUDIO
// https://marketplace.visualstudio.com/items?itemName=ErikEJ.SQLServerCompactSQLiteToolbox
#include "BankTransaction.h"
#include <iostream>
#include <sqlite3.h>
const char* dbPath = "BANK.DB";

enum Options {
    PRINT = 1, NEW, WITHDRAW, DEPOSIT,
    CLOSE, END
};

int MainMenu()
{
    cout << "\nMenu Options" << endl
        << "1 - Print All Account"
        << endl << "2 - Open New Account" << endl
        << "3 - Withdraw" << endl << "4 - Deposit"
        << endl << "5 - Close Account" << endl
        << "6 - End Transaction" << endl;
    int ch;
    cin >> ch;
    return ch;
}

int main()
{
 
    BankTransaction bankTransaction;
    int choice;
    int accountNumber;
    string firstName, lastName;
    double balance;

    while (1) {
        choice = MainMenu();
        if (choice == END)
            break;
        switch (choice) {
        case PRINT:
            bankTransaction.PrintAllAccounts();
            break;
        case NEW:
            cout << "\nEnter account no, first name,last name, balance : "<< endl << "? ";
            cin >> accountNumber;
            cin >> firstName;
            cin >> lastName;
            cin >> balance;
            if (accountNumber < 1) {
                cout << "Invalid account number." << endl;
                break;
            }
            bankTransaction.CreateAccount(BankAccount(accountNumber, firstName, lastName, balance));
            break;
        case WITHDRAW:
            cout << "\nEnter account no, amount to withdraw "<< endl << "? ";
            cin >> accountNumber;
            cin >> balance;
            if (balance < 0) {
                cout << "Invalid amount." << endl;
                break;
            }
            bankTransaction.Withdraw(accountNumber, balance);
            break;
        case DEPOSIT:
            cout << "\nEnter account no, amount to deposit " << endl << "? ";
            cin >> accountNumber;
            cin >> balance;
            if (balance < 0) {
                cout << "Invalid amount." << endl;
                break;
            }
            bankTransaction.Deposit(accountNumber, balance);
            break;
        case CLOSE:
            cout << "\nEnter account no to close account "
                << endl << "? ";
            cin >> accountNumber;
            bankTransaction.CloseAccount(accountNumber);
            break;
        default:
            cerr << "Invalid choice!" << endl;
            break;
        }
    }














    //db.OpenConnection(dbPath);

    //Database::CreateTable(db); // if exists comment this line
   // Product product("Bread", "Black bread", 2.52);
    //Database::Insert(db, product); // Insert product

   // db.CreateDummyTable(dbPath);

    //BankAccount* ba = new BankAccount();
    //ba->SetFirstName("Markovic");
    //ba->SetBalance(4521);
    //ba->SetLastName("Polovic");
    //ba->SetAccountNumber(31);
    ////
    //bankTransaction.CreateAccount(ba);
    
    //bankTransaction.Deposit(999, 100);
    //bankTransaction.CloseAccount(1241);
    
    //bankTransaction.PrintAllAccounts();
    //BankAccount* baa = bankTransaction.GetAccount(999);
    //cout << baa->GetBalance();
    //bankTransaction.Withdraw(999, 123);
    //cout << baa->GetBalance();
    //db.CloseConnection();
    return 0;
}

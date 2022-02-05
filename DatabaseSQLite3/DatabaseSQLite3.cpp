// DatabaseSQLite3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// TOOBOX FOR SQLITE PREVIEW INSIDE VISUAL STUDIO
// https://marketplace.visualstudio.com/items?itemName=ErikEJ.SQLServerCompactSQLiteToolbox
#include "BankTransaction.h"
#include <iostream>
#include <sqlite3.h>
const char* dbPath = "BANK.DB";
int main()
{
 
    BankTransaction bankTransaction;
    //db.OpenConnection(dbPath);

    //Database::CreateTable(db); // if exists comment this line
   // Product product("Bread", "Black bread", 2.52);
    //Database::Insert(db, product); // Insert product

   // db.CreateDummyTable(dbPath);

    //BankAccount* ba = new BankAccount();
    //ba->SetFirstName("Markovic");
    //ba->SetBalance(1421);
    //ba->SetLastName("Polovic");
    //ba->SetAccountNumber(1243);
    //
    //bankTransaction.CreateAccount(ba);
    
    //bankTransaction.Deposit(999, 100);
    //bankTransaction.CloseAccount(1241);
    
    //bankTransaction.PrintAllAccounts();
    BankAccount* baa = bankTransaction.GetAccount(999);
    //cout << baa->GetBalance();
    bankTransaction.Withdraw(999, 123);
    //cout << baa->GetBalance();
    //db.CloseConnection();

}

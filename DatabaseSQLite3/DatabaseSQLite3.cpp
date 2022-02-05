// DatabaseSQLite3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// TOOBOX FOR SQLITE PREVIEW INSIDE VISUAL STUDIO
// https://marketplace.visualstudio.com/items?itemName=ErikEJ.SQLServerCompactSQLiteToolbox
#include "BankTransaction.h"
#include <iostream>
#include <sqlite3.h>
const char* dbPath = "BANK.DB";
int main()
{
  
        
    BankTransaction db;
    db.OpenConnection(dbPath);

    //Database::CreateTable(db); // if exists comment this line
   // Product product("Bread", "Black bread", 2.52);
    //Database::Insert(db, product); // Insert product

    //db.CreateDummyTable(dbPath);

    BankAccount* ba = new BankAccount();
    ba->SetFirstName("Marius");
    ba->SetBalance(5555);
    ba->SetLastName("GZ");
    ba->SetAccountNumber(1241);
    db.CreateAccount(ba);
    db.PrintAllAccounts();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

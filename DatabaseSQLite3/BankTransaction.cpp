#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "BankTransaction.h"
#include "BankAccount.h"


int BankTransaction::OpenConnection(const char* dbPath)
{
    return sqlite3_open(dbPath, &_connection);
}
void BankTransaction::CloseConnection() {
    sqlite3_close(_connection);
}

BankAccount* BankTransaction::GetAccount(int accountNumber){
    OpenConnection("BANK.DB");
    char* zErrMsg = nullptr;
    sqlite3_stmt* statment;
    const char* data = "Callback function called";
    /* Create SQL statement */
    const char* sql ="SELECT * FROM bank_account WHERE ACCOUNT_ID=?";

    /* Execute SQL statement */
   // int rc = sqlite3_exec(_connection, sql, Callback, (void*)data, &zErrMsg);
    if (sqlite3_prepare_v2(_connection, sql, -1, &statment, nullptr) != SQLITE_OK){
        return nullptr;
    }
    
    if (sqlite3_bind_int(statment, 1, accountNumber) != SQLITE_OK) {
        printf("\nCould not bind integer.\n");
        return nullptr;
    }
    CloseConnection();
    return new BankAccount(accountNumber, "Marius", "Mariukanas", 2025.89);
}







void BankTransaction::Withdraw(int accountNumber, double amount)
{
    /*BankAccount* b = GetAccount(accountNumber);
    if (b != NULL) {
        if (b->getBalance() < amount)
            message("Cannot withdraw. Try lower amount.");
        else {
            b->setBalance(b->getBalance() - amount);
            stringstream sql;
            sql << "UPDATE bank_account SET balance="
                << b->getBalance()
                << " WHERE acc_no=" << acno;
            if (!mysql_query(db_conn, sql.str().c_str())) {
                message("Cash withdraw successful.
                    Balance updated.");
            }
            else {
                message("Cash deposit unsuccessful!
                    Update failed");
            }
        }
    }*/
}

void BankTransaction::Deposit(int acno, double amount)
{
 /*   stringstream sql;
    sql << "UPDATE bank_account SET balance=balance+" << amount
        << " WHERE acc_no=" << acno;
    if (!mysql_query(db_conn, sql.str().c_str())) {
        message("Cash deposit successful. Balance updated.");
    }
    else {
        message("Cash deposit unsuccessful! Update failed");
    }*/
}



void BankTransaction::CreateAccount(BankAccount* ba)
{
    
    
    sqlite3_stmt* statment;
    string sql;
    sql = "insert into BANK_ACCOUNT VALUES (?,?,?,?)";


    if (sqlite3_prepare_v2(_connection,
        sql.c_str(),
        -1,
        &statment,
        nullptr)
        != SQLITE_OK) {

    }
    if (sqlite3_bind_null(
        statment,
        1  // Index of wildcard
    ) != SQLITE_OK) {
        printf("\nCould not bind autoicrement.\n");
        return;
    }
    if (sqlite3_bind_text(
        statment,
        2,  // Index of wildcard
        ba->GetFirstName().c_str(), // Data as -> const * char
        ba->GetFirstName().length(), // Data length
        SQLITE_STATIC
    ) != SQLITE_OK) {
        printf("\nCould not bind double.\n");
        return;
    }
    if (sqlite3_bind_text(
        statment,
        3,  // Index of wildcard
        ba->GetLastName().c_str(), // Data as -> const * char
        ba->GetLastName().length(), // Data length
        SQLITE_STATIC
    ) != SQLITE_OK) {
        printf("\nCould not bind double.\n");
        return;
    }
    if (sqlite3_bind_double(
        statment,
        4,  // Index of wildcard
        ba->GetBalance()
    ) != SQLITE_OK) {
        printf("\nCould not bind int.\n");
        return;
    }

    if (sqlite3_step(statment) != SQLITE_DONE) {
        printf("\nCould not step (execute) stmt.\n");
        return;
    }

    printf("\n");
    //select_stmt("select * from foo");

    CloseConnection();
    
    
}

void BankTransaction::CloseAccount(int accountNumber)
{

    OpenConnection("BANK.DB");
    const char* sql = "DELETE FROM BANK_ACCOUNT WHERE ACCOUNT_ID=?";
    sqlite3_stmt* statment;
 
    if (sqlite3_prepare_v2(_connection, sql, -1, &statment, nullptr) != SQLITE_OK) 

    if (sqlite3_bind_int(statment, 1, accountNumber) != SQLITE_OK) {
        printf("\nCould not bind integer.\n");
        return;
    }

    char* zErrMsg = nullptr;
    const char* data = "Callback function called";


    /* Execute SQL statement */
    int rc = sqlite3_exec(_connection, sql, Callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

void BankTransaction::Message(string msg)
{
    cout << msg << endl;
}
void BankTransaction::PrintAllAccounts()
{
    char* zErrMsg = nullptr;
    const char* data = "Callback function called";

    /* Create SQL statement */
    const char* sql = "SELECT * from BANK_ACCOUNT";

    /* Execute SQL statement */
    int rc = sqlite3_exec(_connection, sql, Callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Operation done successfully\n");
    }

}



//void Database::Insert(const Product& product) {
//
//    sqlite3_stmt* statment;
//    string sql;
//    sql = "insert into PRODUCTS VALUES (?,?,?,?)";
//
//
//    if (sqlite3_prepare_v2(_connection,
//        sql.c_str(),
//        -1,
//        &statment,
//        nullptr)
//        != SQLITE_OK) {
//
//    }
//    if (sqlite3_bind_null(
//        statment,
//        1  // Index of wildcard
//    ) != SQLITE_OK) {
//        printf("\nCould not bind double.\n");
//        return;
//    }
//    if (sqlite3_bind_text(
//        statment,
//        2,  // Index of wildcard
//        product.GetName().c_str(), // Data as -> const * char
//        product.GetName().length(), // Data length
//        SQLITE_STATIC
//    ) != SQLITE_OK) {
//        printf("\nCould not bind double.\n");
//        return;
//    }
//    if (sqlite3_bind_text(
//        statment,
//        3,  // Index of wildcard
//        product.GetDescription().c_str(), // Data as -> const * char
//        product.GetDescription().length(), // Data length
//        SQLITE_STATIC
//    ) != SQLITE_OK) {
//        printf("\nCould not bind double.\n");
//        return;
//    }
//    if (sqlite3_bind_double(
//        statment,
//        4,  // Index of wildcard
//        product.GetPrice()
//    ) != SQLITE_OK) {
//        printf("\nCould not bind int.\n");
//        return;
//    }
//
//    if (sqlite3_step(statment) != SQLITE_DONE) {
//        printf("\nCould not step (execute) stmt.\n");
//        return;
//    }
//
//    printf("\n");
//    //select_stmt("select * from foo");
//
//    CloseConnection();
//
//}
//
void BankTransaction::CreateDummyTable(const char* dbPath) {

    const char* sql;
    char* zErrMsg = nullptr;

    /* Open database */
    int rc = OpenConnection(dbPath);
    if (rc) {
        cout << "CAN'T OPEN DATABASE!" << endl;
    }
    else {
        cout << "DATABASE SUCCESSFULLY OPENED!" << endl;
    }

    /* Create SQL statement */
    sql = "CREATE TABLE BANK_ACCOUNT("  \
        "ACCOUNT_ID INTEGER PRIMARY KEY AUTOINCREMENT," \
        "FIRSTNAME           TEXT    NOT NULL," \
        "LASTNAME            TEXT     NOT NULL," \
        "BALANCE        REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(_connection, sql, Callback, nullptr, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Table created successfully\n");
    }
    CloseConnection();
}


//void BankTransaction::Display() {
//
//    char* zErrMsg = nullptr;
//    const char* data = "Callback function called";
//
//    /* Create SQL statement */
//    string sql = "SELECT * from PRODUCTS";
//
//    /* Execute SQL statement */
//    int rc = sqlite3_exec(_connection, sql.c_str(), Callback, (void*)data, &zErrMsg);
//
//    if (rc != SQLITE_OK) {
//        fprintf(stderr, "SQL error: %s\n", zErrMsg);
//        sqlite3_free(zErrMsg);
//    }
//    else {
//        fprintf(stdout, "Operation done successfully\n");
//    }
//}

int BankTransaction::Callback(void* context, int columnCount, char** columnValues, char** columnName) {

    for (int i = 0; i < columnCount; i++) {
        cout << columnName <<" " << columnValues[i] << " ";
    }
    cout << endl;

    return 0;
}
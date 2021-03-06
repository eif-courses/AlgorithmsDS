#pragma once
#include <sqlite3.h>
#include "Product.h"
#include <iostream>
#include <vector>
using namespace std;

class Database {

private: 
    sqlite3* _connection;
public:
    int OpenConnection(const char* dbPath);
    void CloseConnection();

    void CreateDummyTable(const char* dbPath);
    void Insert( const Product& product);
    void Display();
    static int Callback(void* context,  // user-provided object (4th param to sqlite3_exec)
        int columnCount,      // number of columns
        char** columnValues,  // array of column values as C-style strings
        char** columnName);    // array of column names as C-style strings);

};



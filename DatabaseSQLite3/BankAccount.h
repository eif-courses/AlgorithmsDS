#pragma once
#include <iostream>
using std::string;

class BankAccount
{
public:
	BankAccount(int = 0, string = "", string = "", double = 0.0);

	void SetAccountNumber(int accountNumber);
	void SetLastName(string lastName);
	void SetFirstName(string firstName);
	void SetBalance(double balance);

	int GetAccountNumber() const;
	string GetFirstName() const;
	string GetLastName() const;
	double GetBalance() const;

private:
	int _accountNumber;
	string _firstName;
	string _lastName;
	double _balance;
};


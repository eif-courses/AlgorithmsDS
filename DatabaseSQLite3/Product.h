#pragma once
#include <iostream>
using namespace std;
class Product {
private:
	string name;
	string description;
	double price;
public:
	Product(const string& name, const string& description, double price);

	const string& GetName() const;

	const string& GetDescription() const;

	double GetPrice() const;


};

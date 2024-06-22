#include <iostream>
#include <string> 
using namespace std;

#pragma once
class Account
{
	friend ostream& operator<<(ostream& output, const Account& customer); // operator overloading
private:
	char name[30];
	double money;
	int accountId;
	static int accountIdGenerator;
	Account* next; // pointer to the next object using linked list
public:
	Account() : name(), money(),accountId(),next(NULL) {};
	Account(const char* name, double money = 0); // default values - right to left
	char* GetName() const; // return a pointer to the beggining of the array
	void SetName(const char* new_name); // in "set" functions work with new names for the variables
	void SetNext(Account &next_account); // recieve a reference to an Account object
	Account* GetNext() const;
	void print() const;
};
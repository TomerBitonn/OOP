#include <iostream>
#include <string> 
using namespace std;

#pragma once
class Account
{
	friend ostream& operator<<(ostream& output, const Account& customer); 
private:
	char name[30];
	double money;
	int accountId;
	static int accountIdGenerator;
	Account* next; 
public:
	Account() : name(), money(),accountId(),next(NULL) {};
	Account(const char* name, double money = 0); 
	char* GetName() const; 
	void SetName(const char* new_name); 
	void SetNext(Account &next_account); 
	Account* GetNext() const;
	void print() const;
};
